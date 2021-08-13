﻿//-----------------------------------------------
//
//	This file is part of the Siv3D Engine.
//
//	Copyright (c) 2008-2021 Ryo Suzuki
//	Copyright (c) 2016-2021 OpenSiv3D Project
//
//	Licensed under the MIT License.
//
//-----------------------------------------------

# include <variant>
# include <Siv3D/JSON.hpp>
# include <Siv3D/TextReader.hpp>
# include <Siv3D/TextWriter.hpp>
# include <Siv3D/Unicode.hpp>
# include <ThirdParty/nlohmann/json.hpp>

namespace s3d
{
	namespace detail
	{
		struct JSONIteratorDetail
		{
			nlohmann::json::iterator it;

			JSONIteratorDetail() = default;

			explicit JSONIteratorDetail(nlohmann::json::iterator _it)
				: it{ _it } {}
		};

		struct JSONConstIteratorDetail
		{
			nlohmann::json::const_iterator it;

			JSONConstIteratorDetail() = default;

			explicit JSONConstIteratorDetail(nlohmann::json::const_iterator _it)
				: it{ _it } {}
		};

		struct JSONIterationProxyDetail
		{
			nlohmann::detail::iteration_proxy_value<nlohmann::json::iterator> it;

			explicit JSONIterationProxyDetail(nlohmann::detail::iteration_proxy_value<nlohmann::json::iterator> _it)
				: it{ _it } {}
		};

		class JSONDetail
		{
		private:

			using ValueType = nlohmann::json;

			using RefType = std::reference_wrapper<ValueType>;

			static constexpr size_t ValueIndex = 0;

			static constexpr size_t RefIndex = 1;

			std::variant<ValueType, RefType> m_json;

		public:

			struct Value {};

			struct Ref {};

			JSONDetail() = default;

			JSONDetail(Value, nlohmann::json&& _json)
				: m_json{ std::move(_json) } {}

			JSONDetail(Ref, nlohmann::json& _json)
				: m_json{ std::ref(_json) } {}

			nlohmann::json& get()
			{
				return (m_json.index() == ValueIndex) ?
					std::get<ValueType>(m_json) : std::get<RefType>(m_json).get();
			}

			const nlohmann::json& get() const
			{
				return (m_json.index() == ValueIndex) ?
					std::get<ValueType>(m_json) : std::get<RefType>(m_json).get();
			}
		};
	}

	//////////////////////////////////////////////////
	//
	//	JSONIterator
	//
	//////////////////////////////////////////////////

	JSONIterator::JSONIterator(const JSONIterator& rhs)
		: m_detail{ std::make_shared<detail::JSONIteratorDetail>(*rhs.m_detail) } {}

	JSONIterator::JSONIterator(const detail::JSONIteratorDetail& d)
		: m_detail{ std::make_shared<detail::JSONIteratorDetail>(d.it) } {}

	JSONIterator& JSONIterator::operator =(const JSONIterator& rhs)
	{
		JSONIterator tmp = rhs;

		m_detail = std::move(tmp.m_detail);

		return *this;
	}

	JSONIterator& JSONIterator::operator++()
	{
		++m_detail->it;

		return *this;
	}

	JSONIterator JSONIterator::operator++(int)
	{
		const detail::JSONIteratorDetail tmp{ m_detail->it++ };

		return JSONIterator{ tmp };
	}

	JSONIterator JSONIterator::operator+(size_t index) const
	{
		const detail::JSONIteratorDetail tmp{ m_detail->it + index };

		return JSONIterator{ tmp };
	}

	JSONItem JSONIterator::operator *() const
	{
		return{ key(), value() };
	}

	String JSONIterator::key() const
	{
		return Unicode::FromUTF8(m_detail->it.key());
	}

	JSON JSONIterator::value() const
	{
		return JSON(std::make_shared<detail::JSONDetail>(detail::JSONDetail::Ref(), *m_detail->it));
	}

	bool JSONIterator::operator ==(const JSONIterator& other) const noexcept
	{
		return (m_detail->it == other.m_detail->it);
	}

	bool JSONIterator::operator !=(const JSONIterator& other) const noexcept
	{
		return !(*this == other);
	}

	//////////////////////////////////////////////////
	//
	//	JSONConstIterator
	//
	//////////////////////////////////////////////////

	JSONConstIterator::JSONConstIterator(const JSONConstIterator& rhs)
		: m_detail{ std::make_shared<detail::JSONConstIteratorDetail>(*rhs.m_detail) } {}

	JSONConstIterator::JSONConstIterator(const detail::JSONConstIteratorDetail& d)
		: m_detail{ std::make_shared<detail::JSONConstIteratorDetail>(d.it) } {}

	JSONConstIterator& JSONConstIterator::operator =(const JSONConstIterator& rhs)
	{
		JSONConstIterator tmp = rhs;

		m_detail = std::move(tmp.m_detail);

		return *this;
	}

	JSONConstIterator& JSONConstIterator::operator++()
	{
		++m_detail->it;

		return *this;
	}

	JSONConstIterator JSONConstIterator::operator++(int)
	{
		const detail::JSONConstIteratorDetail tmp{ m_detail->it++ };

		return JSONConstIterator{ tmp };
	}

	JSONConstIterator JSONConstIterator::operator+(size_t index) const
	{
		const detail::JSONConstIteratorDetail tmp{ m_detail->it + index };

		return JSONConstIterator{ tmp };
	}

	const JSONItem JSONConstIterator::operator *() const
	{
		return{ key(), value() };
	}

	String JSONConstIterator::key() const
	{
		return Unicode::FromUTF8(m_detail->it.key());
	}

	const JSON JSONConstIterator::value() const
	{
		return JSON(std::make_shared<detail::JSONDetail>(detail::JSONDetail::Ref(), const_cast<nlohmann::json&>(*m_detail->it)));
	}

	bool JSONConstIterator::operator ==(const JSONConstIterator& other) const noexcept
	{
		return (m_detail->it == other.m_detail->it);
	}

	bool JSONConstIterator::operator !=(const JSONConstIterator& other) const noexcept
	{
		return !(*this == other);
	}

	//////////////////////////////////////////////////
	//
	//	JSONIterationProxy
	//
	//////////////////////////////////////////////////

	JSONIterationProxy::JSONIterationProxy(const JSONIterationProxy& rhs)
		: m_detail{ std::make_shared<detail::JSONIterationProxyDetail>(*rhs.m_detail) } {}

	JSONIterationProxy::JSONIterationProxy(const detail::JSONIterationProxyDetail& d)
		: m_detail{ std::make_shared<detail::JSONIterationProxyDetail>(d.it) } {}

	JSONIterationProxy& JSONIterationProxy::operator =(const JSONIterationProxy& rhs)
	{
		JSONIterationProxy tmp = rhs;

		m_detail = std::move(tmp.m_detail);

		return *this;
	}

	JSONIterationProxy& JSONIterationProxy::operator++()
	{
		++m_detail->it;

		return *this;
	}

	JSONIterationProxy JSONIterationProxy::operator++(int)
	{
		const detail::JSONIterationProxyDetail tmp{ m_detail->it };

		++m_detail->it;

		return JSONIterationProxy{ tmp };
	}

	JSONIterationProxy JSONIterationProxy::operator+(size_t index) const
	{
		auto it = m_detail->it;

		std::advance(it, index);

		return JSONIterationProxy{ detail::JSONIterationProxyDetail{ it } };
	}

	JSON JSONIterationProxy::operator *() const
	{
		return JSON(std::make_shared<detail::JSONDetail>(detail::JSONDetail::Ref(), m_detail->it.value()));
	}

	bool JSONIterationProxy::operator ==(const JSONIterationProxy& other) const noexcept
	{
		return (m_detail->it == other.m_detail->it);
	}

	bool JSONIterationProxy::operator !=(const JSONIterationProxy& other) const noexcept
	{
		return !(*this == other);
	}

	//////////////////////////////////////////////////
	//
	//	JSONArrayView
	//
	//////////////////////////////////////////////////

	JSONArrayView::JSONArrayView(JSONIterationProxy begin, JSONIterationProxy end)
		: m_begin{ begin }
		, m_end{ end } {}

	JSONIterationProxy JSONArrayView::begin() const
	{
		return m_begin;
	}

	JSONIterationProxy JSONArrayView::end() const
	{
		return m_end;
	}

	JSON JSONArrayView::operator [](const size_t index) const
	{
		return *(m_begin + index);
	}

	//////////////////////////////////////////////////
	//
	//	JSON
	//
	//////////////////////////////////////////////////

	JSON::JSON()
		: JSON(nullptr) {}

	JSON::JSON(Invalid_)
		: m_detail{ std::make_shared<detail::JSONDetail>() }
		, m_isValid{ false } {}

	JSON::JSON(std::nullptr_t)
		: m_detail{ std::make_shared<detail::JSONDetail>() } {}

	JSON::JSON(std::shared_ptr<detail::JSONDetail>&& detail)
		: m_detail{ std::move(detail) } {}

	JSON::JSON(const std::initializer_list<std::pair<String, JSON>>& list)
		: m_detail{ std::make_shared<detail::JSONDetail>() }
	{
		operator =(list);
	}

	JSON::JSON(const Array<JSON>& array)
		: m_detail{ std::make_shared<detail::JSONDetail>() }
	{
		*this = array;
	}

	JSON::JSON(const StringView value)
		: m_detail{ std::make_shared<detail::JSONDetail>(detail::JSONDetail::Value(), nlohmann::json(Unicode::ToUTF8(value))) } {}

	JSON::JSON(const int64 value)
		: m_detail{ std::make_shared<detail::JSONDetail>(detail::JSONDetail::Value(), nlohmann::json(value)) } {}

	JSON::JSON(const uint64 value)
		: m_detail{ std::make_shared<detail::JSONDetail>(detail::JSONDetail::Value(), nlohmann::json(value)) } {}

	JSON::JSON(const double value)
		: m_detail{ std::make_shared<detail::JSONDetail>(detail::JSONDetail::Value(), nlohmann::json(value)) } {}

	JSON::JSON(const bool value)
		: m_detail{ std::make_shared<detail::JSONDetail>(detail::JSONDetail::Value(), nlohmann::json(value)) } {}

	JSON& JSON::operator =(std::nullptr_t)
	{
		if (not m_isValid)
		{
			return *this;
		}

		m_detail->get() = nullptr;

		return *this;
	}

	JSON& JSON::operator =(const JSON& value)
	{
		if (not m_isValid)
		{
			return *this;
		}

		m_detail->get() = value.m_detail->get();

		return *this;
	}

	JSON& JSON::operator =(const std::initializer_list<std::pair<String, JSON>>& list)
	{
		if (not m_isValid)
		{
			return *this;
		}

		for (const auto& element : list)
		{
			m_detail->get()[Unicode::ToUTF8(element.first)] = element.second.m_detail->get();
		}

		return *this;
	}

	JSON& JSON::operator =(const Array<JSON>& array)
	{
		if (not m_isValid)
		{
			return *this;
		}

		for (const auto& element : array)
		{
			m_detail->get().push_back(element.m_detail->get());
		}

		return *this;
	}

	JSON& JSON::operator =(const StringView value)
	{
		if (not m_isValid)
		{
			return *this;
		}

		m_detail->get() = Unicode::ToUTF8(value);

		return *this;
	}

	JSON& JSON::operator =(const int64 value)
	{
		if (not m_isValid)
		{
			return *this;
		}

		m_detail->get() = value;

		return *this;
	}

	JSON& JSON::operator =(const uint64 value)
	{
		if (not m_isValid)
		{
			return *this;
		}

		m_detail->get() = value;

		return *this;
	}

	JSON& JSON::operator =(const double value)
	{
		if (not m_isValid)
		{
			return *this;
		}

		m_detail->get() = value;

		return *this;
	}

	JSON& JSON::operator =(const bool value)
	{
		if (not m_isValid)
		{
			return *this;
		}

		m_detail->get() = value;

		return *this;
	}

	bool JSON::operator ==(const JSON& other) const
	{
		if (not m_isValid)
		{
			return (not other.m_isValid);
		}

		return (m_detail->get() == other.m_detail->get());
	}

	bool JSON::operator !=(const JSON& other) const
	{
		return !(*this == other);
	}

	bool JSON::isEmpty() const
	{
		return (not m_isValid);
	}

	JSON::operator bool() const
	{
		return m_isValid;
	}

	bool JSON::isNull() const
	{
		if (not m_isValid)
		{
			return false;
		}

		return m_detail->get().is_null();
	}

	bool JSON::isBool() const
	{
		if (not m_isValid)
		{
			return false;
		}

		return m_detail->get().is_boolean();
	}

	bool JSON::isNumber() const
	{
		if (not m_isValid)
		{
			return false;
		}

		return m_detail->get().is_number();
	}

	bool JSON::isInteger() const
	{
		if (not m_isValid)
		{
			return false;
		}

		return m_detail->get().is_number_integer();
	}

	bool JSON::isUnsigned() const
	{
		if (not m_isValid)
		{
			return false;
		}

		return m_detail->get().is_number_unsigned();
	}

	bool JSON::isFloat() const
	{
		if (not m_isValid)
		{
			return false;
		}

		return m_detail->get().is_number_float();
	}

	bool JSON::isString() const
	{
		if (not m_isValid)
		{
			return false;
		}

		return m_detail->get().is_string();
	}

	bool JSON::isArray() const
	{
		if (not m_isValid)
		{
			return false;
		}

		return m_detail->get().is_array();
	}

	bool JSON::isObject() const
	{
		if (not m_isValid)
		{
			return false;
		}

		return m_detail->get().is_object();
	}

	JSONValueType JSON::getType() const
	{
		if (not m_isValid)
		{
			return JSONValueType::Empty;
		}

		if (isArray())
		{
			return JSONValueType::Array;
		}
		else if (isBool())
		{
			return JSONValueType::Bool;
		}
		else if (isNull())
		{
			return JSONValueType::Null;
		}
		else if (isNumber())
		{
			return JSONValueType::Number;
		}
		else if (isObject())
		{
			return JSONValueType::Object;
		}
		else if (isString())
		{
			return JSONValueType::String;
		}

		throw Error{ U"JSON::getType(): Unknown JSONValueType" };
	}

	bool JSON::hasElement(const StringView name) const
	{
		if (not m_isValid)
		{
			return false;
		}

		return m_detail->get().contains(Unicode::ToUTF8(name));
	}

	String JSON::getString() const
	{
		if (not isString())
		{
			throw Error{ U"JSON::getString(): Value is not a String type" };
		}

		return Unicode::FromUTF8(m_detail->get().get<std::string>());
	}

	JSON JSON::operator [](const StringView name)
	{
		if (not m_isValid)
		{
			return JSON::Invalid();
		}

		const std::string key = Unicode::ToUTF8(name);

		return JSON(std::make_shared<detail::JSONDetail>(
			detail::JSONDetail::Ref(), *m_detail->get().emplace(key, nlohmann::json()).first));
	}

	const JSON JSON::operator [](const StringView name) const
	{
		if (not m_isValid)
		{
			return JSON::Invalid();
		}

		const std::string key = Unicode::ToUTF8(name);

		const auto it = m_detail->get().find(key);

		if (it != m_detail->get().end())
		{
			return JSON(std::make_shared<detail::JSONDetail>(detail::JSONDetail::Ref(), *it));
		}

		throw Error{ U"JSON::operator [](): Key `{}` not found"_fmt(name) };
	}

	JSON JSON::operator [](const size_t index)
	{
		if (not m_isValid)
		{
			return JSON::Invalid();
		}

		if (not isArray())
		{
			throw Error{ U"JSON::operator [](size_t): Value is not an Array type" };
		}

		if (index >= m_detail->get().size())
		{
			throw Error{ U"JSON::operator [](size_t): Index out of range" };
		}

		return JSON(std::make_shared<detail::JSONDetail>(detail::JSONDetail::Ref(), m_detail->get()[index]));
	}

	const JSON JSON::operator [](const size_t index) const
	{
		if (not m_isValid)
		{
			return JSON::Invalid();
		}

		if (not isArray())
		{
			throw Error{ U"JSON::operator [](size_t): Value is not an Array type" };
		}

		if (const size_t size = m_detail->get().size();
			index >= size)
		{
			throw Error{ U"JSON::operator [](size_t): Index out of range (index: {} >= size: {})"_fmt(index, size) };
		}

		return JSON(std::make_shared<detail::JSONDetail>(detail::JSONDetail::Ref(), m_detail->get()[index]));
	}

	JSON JSON::access(const StringView jsonPointer)
	{
		if (not jsonPointer.starts_with(U'/'))
		{
			throw Error{ U"JSON::access(): Invalid JSON pointer `{}`"_fmt(jsonPointer) };
		}

		if (isObject() || isArray() || isNull())
		{
			return JSON(std::make_shared<detail::JSONDetail>(detail::JSONDetail::Ref(), m_detail->get()[nlohmann::json::json_pointer(Unicode::ToUTF8(jsonPointer))]));
		}

		throw Error{ U"JSON::access(): Invalid JSON type" };
	}

	const JSON JSON::access(const StringView jsonPointer) const
	{
		if (not jsonPointer.starts_with(U'/'))
		{
			throw Error{ U"JSON::access(): Invalid JSON pointer `{}`"_fmt(jsonPointer) };
		}

		if (isObject() || isArray() || isNull())
		{
			return JSON(std::make_shared<detail::JSONDetail>(detail::JSONDetail::Ref(), m_detail->get()[nlohmann::json::json_pointer(Unicode::ToUTF8(jsonPointer))]));
		}

		throw Error{ U"JSON::access(): Invalid JSON type" };
	}

	void JSON::clear() const
	{
		if (not m_isValid)
		{
			return;
		}

		m_detail->get().clear();
	}

	void JSON::erase(const StringView name)
	{
		if (not m_isValid)
		{
			return;
		}

		const std::string key = Unicode::ToUTF8(name);

		m_detail->get().erase(key);
	}

	//JSON::iterator JSON::find(const StringView name)
	//{
	//	const std::string key = Unicode::ToUTF8(name);

	//	return iterator(detail::JSONIteratorDetail(m_detail->get().find(key)));
	//}

	//JSON::const_iterator JSON::find(const StringView name) const
	//{
	//	const std::string key = Unicode::ToUTF8(name);

	//	return const_iterator(detail::JSONConstIteratorDetail(m_detail->get().find(key)));
	//}

	JSON::iterator JSON::begin()
	{
		return iterator{ detail::JSONIteratorDetail(m_detail->get().begin()) };
	}

	JSON::const_iterator JSON::begin() const
	{
		return const_iterator{ detail::JSONConstIteratorDetail(m_detail->get().begin()) };
	}

	JSON::iterator JSON::end()
	{
		return iterator{ detail::JSONIteratorDetail(m_detail->get().end()) };
	}

	JSON::const_iterator JSON::end() const
	{
		return const_iterator{ detail::JSONConstIteratorDetail(m_detail->get().end()) };
	}

	JSONArrayView JSON::arrayView() const
	{
		if (not isArray())
		{
			throw Error{ U"JSON::arrayView(): Value is not an Array type" };
		}

		return JSONArrayView{
			JSONIterationProxy{ detail::JSONIterationProxyDetail(m_detail->get().items().begin()) },
			JSONIterationProxy{ detail::JSONIterationProxyDetail(m_detail->get().items().end()) }
		};
	}

	size_t JSON::size() const
	{
		if (not m_isValid)
		{
			return 0;
		}

		return m_detail->get().size();
	}

	String JSON::format(const char32 space, const size_t spaceCount) const
	{
		return Unicode::FromUTF8(formatUTF8(space, spaceCount));
	}

	String JSON::formatMinimum() const
	{
		return Unicode::FromUTF8(formatUTF8Minimum());
	}

	std::string JSON::formatUTF8(const char32 space, const size_t spaceCount) const
	{
		if (not m_isValid)
		{
			return{};
		}

		return m_detail->get().dump(static_cast<int>(spaceCount), static_cast<char>(space));
	}

	std::string JSON::formatUTF8Minimum() const
	{
		if (not m_isValid)
		{
			return{};
		}

		return m_detail->get().dump();
	}

	bool JSON::save(const FilePathView path) const
	{
		if (not m_isValid)
		{
			return false;
		}

		TextWriter writer{ path };

		if (not writer)
		{
			return false;
		}

		writer.write(format());

		return true;
	}

	bool JSON::saveMinimum(const FilePathView path) const
	{
		if (not m_isValid)
		{
			return false;
		}

		TextWriter writer{ path };

		if (not writer)
		{
			return false;
		}

		writer.write(formatMinimum());

		return true;
	}

	JSON JSON::Invalid()
	{
		return JSON(Invalid_{});
	}

	JSON JSON::Load(const FilePathView path, const AllowExceptions allowExceptions)
	{
		TextReader reader{ path };

		if (not reader)
		{
			if (allowExceptions)
			{
				throw Error{ U"JSON::load(): failed to open `{}`"_fmt(path) };
			}

			return JSON::Invalid();
		}

		return Parse(reader.readAll(), allowExceptions);
	}

	JSON JSON::Load(std::unique_ptr<IReader>&& reader, const AllowExceptions allowExceptions)
	{
		TextReader textReader{ std::move(reader) };

		if (not textReader)
		{
			if (allowExceptions)
			{
				throw Error(U"JSON::load(): failed to open from IReader");
			}

			return JSON::Invalid();
		}

		return Parse(textReader.readAll(), allowExceptions);
	}

	JSON JSON::Parse(const StringView str, const AllowExceptions allowExceptions)
	{
		JSON value{ Invalid_{} };

		try
		{
			value.m_detail = std::make_shared<detail::JSONDetail>(detail::JSONDetail::Value(), nlohmann::json::parse(Unicode::ToUTF8(str)));
			value.m_isValid = true;
		}
		catch (const std::exception& e)
		{
			if (not allowExceptions)
			{
				return JSON::Invalid();
			}

			throw Error{ U"JSON::Parse(): " + Unicode::Widen(e.what()) };
		}

		return value;
	}

	void Formatter(FormatData& formatData, const JSON& value)
	{
		Formatter(formatData, value.format());
	}

	Optional<String> JSON::getOptString() const
	{
		if (not isString())
		{
			return none;
		}

		return Unicode::FromUTF8(m_detail->get().get<std::string>());
	}

	Optional<int64> JSON::getOptInt64() const
	{
		if (not isNumber())
		{
			return none;
		}

		if (isBool())
		{
			return static_cast<int64>(m_detail->get().get<bool>());
		}

		return m_detail->get().get<int64>();
	}

	Optional<double> JSON::getOptDouble() const
	{
		if (not isNumber())
		{
			return none;
		}

		return m_detail->get().get<double>();
	}

	Optional<bool> JSON::getOptBool() const
	{
		if (not isBool())
		{
			return none;
		}

		return m_detail->get().get<bool>();
	}
}
