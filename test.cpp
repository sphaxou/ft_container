#include <vector>
#include <iostream>

int main()
{
	std::vector<int> q;
	q.push_back(1);
	q.push_back(2);
	q.push_back(3);
	q.push_back(4);
	std::vector<int>::iterator test = q.begin();
		for (std::vector<int>::iterator it = q.begin(); it != q.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	std::cout << std::endl;
	std::vector<int>::iterator test2 = test - 1;
	test++;
	test++;
	std::cout << *test2 << std::endl;
	q.erase(test, test + 1);
	std::cout << *(test2 + 1) << std::endl;
	for (std::vector<int>::iterator it = q.begin(); it != q.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	return 0;
}