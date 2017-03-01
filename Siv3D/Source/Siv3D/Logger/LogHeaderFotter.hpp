﻿//-----------------------------------------------
//
//	This file is part of the Siv3D Engine.
//
//	Copyright (C) 2008-2017 Ryo Suzuki
//	Copyright (C) 2016-2017 OpenSiv3D Project
//
//	Licensed under the MIT License.
//
//-----------------------------------------------

# pragma once
# include <Siv3D/String.hpp>

const static char headerA[] =
u8R"(<!DOCTYPE html>
<html lang="ja">
<head>
<meta charset="UTF-8" />
<title>)";

const static char headerB[] =
u8R"( Log</title>
<style>
body		{ background-color: #f9f9f9; font-family: 'Segoe UI','メイリオ','Meiryo','ヒラギノ角ゴ Pro W3','Hiragino Kaku Gothic Pro','Osaka','ＭＳ Ｐゴシック','MS PGothic','Arial',sans-serif; }
h2			{ color: #333333; text-align: center; font-size: 28px; }
h3			{ color: #333333; text-align: center; font-size: 24px; }
div			{ font-size: 14px; line-height: 2; word-wrap: break-word; }
div.error	{ padding-left: 14px; background: #f44336; color: #ffffff; }
div.fail	{ padding-left: 14px; background: #ff9800; color: #ffffff; }
div.warning	{ padding-left: 14px; background: #ff9800; color: #ffffff; }
div.script	{ padding-left: 14px; background: #d9eeda; color: #333333; }
div.app		{ padding-left: 14px; background: #ffffff; color: #333333; }
div.info	{ padding-left: 14px; background: #e3f2fd; color: #333333; }
div.debug	{ padding-left: 14px; background: #f5f5f5; color: #333333; }
div.c0		{ color: #333333; text-align: center; font-size: 20px; }
div.c1		{ padding-bottom: 8px; color: #555555; text-align: center; font-size: 12px; }
div.c2		{ padding-bottom: 24px; color: #888888; text-align: center; font-size: 9px; }
div.messages { margin: 0 10% 28px; padding 0 0 28px; border: 1px solid; border-color: #dddddd; border-radius: 2px; box-shadow: 0 1px 1px rgba(0,0,0,.05); }
</style>
</head>
<body>
<h2>)";

const static char headerC[] =
u8R"( Log</h2>
<div class="messages">
)";

const static std::string logLevel[]{
	u8R"(<div class="error">)",
	u8R"(<div class="fail">)",
	u8R"(<div class="warning">)",
	u8R"(<div class="script">)",
	u8R"(<div class="app">)",
	u8R"(<div class="info">)",
	u8R"(<div class="debug">)",
};

const static char divEnd[] = u8"</div>\n";

const static char footer[] =
u8R"-(</div>
<h3>Licenses</h3>
<div class="c0">Siv3D Engine</div>
<div class="c1">Copyright (c) 2008-2017 Ryo Suzuki<br>Copyright (c) 2016-2017 OpenSiv3D Project</div>
<div class="c2">
Permission is hereby granted, free of charge, to any person obtaining a copy<br>
of this software and associated documentation files (the “Software”), to deal<br>
in the Software without restriction, including without limitation the rights<br>
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell<br>
copies of the Software, and to permit persons to whom the Software is<br>
furnished to do so, subject to the following conditions:<br>
<br>
The above copyright notice and this permission notice shall be included in all<br>
copies or substantial portions of the Software.<br>
<br>
THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR<br>
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,<br>
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE<br>
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER<br>
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,<br>
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE<br>
SOFTWARE.<br>
</div>)-"


u8R"-(<div class="c0">double-conversion</div>
<div class="c1">Copyright (c) 2006-2011, the V8 project authors. All rights reserved.</div>
<div class="c2">
Redistribution and use in source and binary forms, with or without<br>
modification, are permitted provided that the following conditions are<br>
met:<br>
<br>
    * Redistributions of source code must retain the above copyright<br>
      notice, this list of conditions and the following disclaimer.<br>
    * Redistributions in binary form must reproduce the above<br>
      copyright notice, this list of conditions and the following<br>
      disclaimer in the documentation and/or other materials provided<br>
      with the distribution.<br>
    * Neither the name of Google Inc. nor the names of its<br>
      contributors may be used to endorse or promote products derived<br>
      from this software without specific prior written permission.<br>
<br>
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS<br>
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT<br>
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR<br>
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT<br>
OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,<br>
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT<br>
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,<br>
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY<br>
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT<br>
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE<br>
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.<br>
</div>)-"


u8R"-(<div class="c0">fmt</div>
<div class="c1">Copyright (c) 2012 - 2016, Victor Zverovich</div>
<div class="c2">
 Redistribution and use in source and binary forms, with or without<br>
 modification, are permitted provided that the following conditions are met:<br>
<br>
 1. Redistributions of source code must retain the above copyright notice, this<br>
    list of conditions and the following disclaimer.<br>
 2. Redistributions in binary form must reproduce the above copyright notice,<br>
    this list of conditions and the following disclaimer in the documentation<br>
    and/or other materials provided with the distribution.<br>
<br>
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND<br>
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED<br>
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE<br>
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR<br>
 ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES<br>
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;<br>
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND<br>
 ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT<br>
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS<br>
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.<br>
</div>)-"


u8R"-(<div class="c0">miniutf</div>
<div class="c1">Copyright (c) 2013 Dropbox, Inc.</div>
<div class="c2">
Permission is hereby granted, free of charge, to any person obtaining a copy<br>
of this software and associated documentation files (the "Software"), to deal<br>
in the Software without restriction, including without limitation the rights<br>
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell<br>
copies of the Software, and to permit persons to whom the Software is<br>
furnished to do so, subject to the following conditions:<br>
<br>
The above copyright notice and this permission notice shall be included in<br>
all copies or substantial portions of the Software.<br>
<br>
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR<br>
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,<br>
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE<br>
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER<br>
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,<br>
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN<br>
THE SOFTWARE.<br>
</div>)-"


u8R"-(<div class="c0">Zstandard</div>
<div class="c1">Copyright (c) 2016-present, Facebook, Inc. All rights reserved.</div>
<div class="c2">
Redistribution and use in source and binary forms, with or without modification,<br>
are permitted provided that the following conditions are met:<br>
<br>
 * Redistributions of source code must retain the above copyright notice, this<br>
   list of conditions and the following disclaimer.<br>
<br>
 * Redistributions in binary form must reproduce the above copyright notice,<br>
   this list of conditions and the following disclaimer in the documentation<br>
   and/or other materials provided with the distribution.<br>
<br>
 * Neither the name Facebook nor the names of its contributors may be used to<br>
   endorse or promote products derived from this software without specific<br>
   prior written permission.<br>
<br>
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND<br>
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED<br>
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE<br>
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR<br>
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES<br>
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;<br>
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON<br>
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT<br>
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS<br>
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.<br>
</div>)-"

# if defined(SIV3D_TARGET_MACOS) || defined(SIV3D_TARGET_LINUX)

u8R"-(<div class="c0">GLFW</div>
<div class="c1">Copyright (c) 2002 - 2006 Marcus Geelnard</div>
<div class="c1">Copyright (c) 2006 - 2016 Camilla Löwy &lt;elmindreda@glfw.org&gt;</div>
<div class="c2">
This software is provided 'as-is', without any express or implied<br>
warranty.In no event will the authors be held liable for any damages<br>
arising from the use of this software.<br>
<br>
Permission is granted to anyone to use this software for any purpose,<br>
including commercial applications, and to alter it and redistribute it<br>
freely, subject to the following restrictions :<br>
<br>
1. The origin of this software must not be misrepresented; you must not<br>
claim that you wrote the original software.If you use this software<br>
in a product, an acknowledgment in the product documentation would<br>
be appreciated but is not required.<br>
<br>
2. Altered source versions must be plainly marked as such, and must not<br>
be misrepresented as being the original software.<br>
<br>
3. This notice may not be removed or altered from any source<br>
distribution.<br>
</div>)-"

# endif

u8R"-(<div class="c0">muparser</div>
<div class="c1">Copyright (c) 2011 Ingo Berg</div>
<div class="c2">
Permission is hereby granted, free of charge, to any person obtaining a copy of this<br>
software and associated documentation files(the "Software"), to deal in the Software<br>
without restriction, including without limitation the rights to use, copy, modify,<br>
merge, publish, distribute, sublicense, and / or sell copies of the Software, and to<br>
permit persons to whom the Software is furnished to do so, subject to the following conditions :<br>
<br>
The above copyright notice and this permission notice shall be included in all copies or<br>
substantial portions of the Software.<br>
<br>
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT<br>
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND<br>
NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,<br>
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,<br>
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.<br>
OR OTHER DEALINGS IN THE SOFTWARE.<br>
</div>)-"

u8R"-(<div class="c0">xxHash</div>
<div class="c1">Copyright (c) 2012-2016, Yann Collet.</div>
<div class="c2">
Redistribution and use in source and binary forms, with or without<br>
modification, are permitted provided that the following conditions are<br>
met:<br>
<br>
* Redistributions of source code must retain the above copyright<br>
notice, this list of conditions and the following disclaimer.<br>
* Redistributions in binary form must reproduce the above<br>
copyright notice, this list of conditions and the following disclaimer<br>
in the documentation and/or other materials provided with the<br>
distribution.<br>
<br>
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS<br>
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT<br>
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR<br>
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT<br>
OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,<br>
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT<br>
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,<br>
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY<br>
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT<br>
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE<br>
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.<br>
</div>)-"

u8R"-(<div class="c0">hopscotch-map</div>
<div class="c1">Copyright (c) 2016 Tessil</div>
<div class="c2">
Permission is hereby granted, free of charge, to any person obtaining a copy<br>
of this software and associated documentation files (the "Software"), to deal<br>
in the Software without restriction, including without limitation the rights<br>
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell<br>
copies of the Software, and to permit persons to whom the Software is<br>
furnished to do so, subject to the following conditions:<br>
<br>
The above copyright notice and this permission notice shall be included in all<br>
copies or substantial portions of the Software.<br>
<br>
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR<br>
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,<br>
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE<br>
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER<br>
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,<br>
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE<br>
SOFTWARE.<br>
</div>)-"

u8R"-(<div class="c0">zlib</div>
<div class="c1">Copyright (c) 1995 - 2017 Jean - loup Gailly and Mark Adler</div>
<div class="c2">
This software is provided 'as-is', without any express or implied<br>
warranty.In no event will the authors be held liable for any damages<br>
arising from the use of this software.<br>
<br>
Permission is granted to anyone to use this software for any purpose,<br>
including commercial applications, and to alter it and redistribute it<br>
freely, subject to the following restrictions :<br>
<br>
1. The origin of this software must not be misrepresented; you must not<br>
claim that you wrote the original software.If you use this software<br>
in a product, an acknowledgment in the product documentation would be<br>
appreciated but is not required.<br>
2. Altered source versions must be plainly marked as such, and must not be<br>
misrepresented as being the original software.<br>
3. This notice may not be removed or altered from any source distribution.<br>
</div>)-"

u8R"-(<div class="c0">libpng</div>
<div class="c1">Copyright (c) 1998-2002,2004,2006-2017 Glenn Randers-Pehrson</div>
<div class="c2">
The PNG Reference Library is supplied "AS IS".  The Contributing Authors<br>
and Group 42, Inc. disclaim all warranties, expressed or implied,<br>
including, without limitation, the warranties of merchantability and of<br>
fitness for any purpose.  The Contributing Authors and Group 42, Inc.<br>
assume no liability for direct, indirect, incidental, special, exemplary,<br>
or consequential damages, which may result from the use of the PNG<br>
Reference Library, even if advised of the possibility of such damage.<br>
<br>
Permission is hereby granted to use, copy, modify, and distribute this<br>
source code, or portions hereof, for any purpose, without fee, subject<br>
to the following restrictions:<br>
<br>
  1. The origin of this source code must not be misrepresented.<br>
<br>
  2. Altered versions must be plainly marked as such and must not<br>
     be misrepresented as being the original source.<br>
<br>
  3. This Copyright notice may not be removed or altered from any<br>
     source or altered source distribution.<br>
</div>)-"

u8R"-(<div class="c0">Convenient Constructs For Stepping Through a Range of Values</div>
<div class="c1">Copyright (c) Mikhail Semenov</div>
<div class="c2">Licenced with the Code Project Open Licence (CPOL) http://www.codeproject.com/info/cpol10.aspx </div>
<br>
</body>
</html>)-";