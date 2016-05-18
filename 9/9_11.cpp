#include <vector>
std::vector<int> vec1;
std::vector<int> vec2{ 2, 3, 4, 5 };
std::vector<int> vec3={ 5, 4, 3, 2 };
std::vector<int> vec4(vec2);
std::vector<int> vec5 = vec3;
std::vector<int> vec6(vec4.begin(), vec4.end());
std::vector<int> vec7(10);
std::vector<int> vec8(10,1);