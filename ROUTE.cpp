
// start:: stdc++ header
// C++ includes used for precompiling -*- C++ -*-

// Copyright (C) 2003-2013 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// Under Section 7 of GPL version 3, you are granted additional
// permissions described in the GCC Runtime Library Exception, version
// 3.1, as published by the Free Software Foundation.

// You should have received a copy of the GNU General Public License and
// a copy of the GCC Runtime Library Exception along with this program;
// see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
// <http://www.gnu.org/licenses/>.

/** @file stdc++.h
 *  This is an implementation file for a precompiled header.
 */

 // 17.4.1.2 Headers

 // C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
// #pragma once
// end:: stdc++ header


// Bài 19 Đường đi
// Các nhà địa chất có nhiệm vụ khảo sát tìm khoáng sản ở một vùng đài nguyên mênh mông.
// Thiết bị và nhu yếu phẩm được chở tới trại Trung tâm tại điểm có tọa độ (0, 0) trên bản đồ.
// Nhóm khảo sát đi thăm dò từng điểm có tọa nguyên trên bản đồ. Nhóm di chuyển từ điểm có
// tọa độ nguyên này tới điểm có tọa độ nguyên khác và luôn đi theo một trong các hướng
// “Đông”(E), “Tây” (W), “Nam” (S) hoặc “Bắc” (N). Việc đổi hướng có thể được thực hiện tại
// các điểm có tọa độ nguyên. Khoảng cách bằng một đơn vị tọa độ được gọi là bước. Đường đi
// của họ được thiết bị tự động mang theo báo về dưới dạng xâu ghi nhận từng nhóm số bước di
// chuyển và hướng. Ví dụ, dòng thông báo “7N5E2S3E” cho biết nhóm đã đi 7 bước theo hướng
// nam, sau đó đi 5 bước về hướng đông, đi tiếp theo hướng bắc 2 bước rồi đi theo hướng đông 3
// bước.
// Có thể tại một nơi nào đó nhóm tìm thấy những mẫu vật đặc biệt, cần phân tích ngay để có
// hành động phù hợp tiếp theo và yêu cầu Trung tâm gửi thiết bị bay tới lấy về. Các thiết bị bay
// mang theo chỉ được lập trình cho đường bay theo các hướng E, W, S và N. Khi nạp thông báo
// về hành trình của nhóm khảo sát vào bộ nhớ, các microchips trong máy bay sẽ tính toán, tìm
// đường đi có xâu (biểu diễn dưới dạng của thiết bị ghi nhận đường đi đã nói ở trên) ngắn nhất.
// Có nhiều cách ngắn nhất để đi tới đích. Hãy xác định một trong số các xâu biểu diễn đường đi
// do thiết bị bay tạo ra. Đảm bảo đích cần tới không trùng với gốc tọa độ.
// Dữ liệu: Vào từ file văn bản ROUTE.INP gồm một dòng chứa xâu độ dài không quá 250 xác
// định hành trình của nhóm khảo sát. Các hệ số có giá trị nguyên dương và không vượt quá 107
// .
// Kết quả: Đưa ra file văn bản ROUTE.OUT xâu do thiết bị bay tạo ra.
// Ví dụ:
// ROUTE.INP  ROUTE.OUT
// 7N5E2S3E   8E5
using namespace std;
#define NAME "ROUTE."
#define LogsTime fo<<"\nTime:"<<clock()/(double)1000<<"sec"
ifstream file_in(NAME"INP");
ofstream file_out(NAME"OUT");  

map<char, int> X {{'E', 1}, {'W', -1}};
map<char, int> Y {{'N', 1}, {'S', -1}};

int x = 0;
int y = 0;
int n;
char dir;
 
int main()
{  
	while (file_in >> n >> dir)
	{
		x += n * X[dir];
		y += n * Y[dir];
	}
	if (x > 0) file_out << x << "E";
	if (x < 0) file_out << -x << "W";
	if (y > 0) file_out << y << "N";
	if (y < 0) file_out << -y << "S"; 
	// LogsTime;
	cout << "\n" << file_out;
	cout << "\nTime:" << clock() / (double)1000 << "sec\n";
	// system("pause");
	return 0;
}
