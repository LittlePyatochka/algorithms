#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>

using namespace std;

struct path
{
	string name;
	std::vector<path> * inner;
};

bool cmp(path & left, path & right) { return left.name < right.name;}


void show(std::vector<path> tree, int level = 0){
	sort(tree.begin(), tree.end(), cmp);
	for(path p : tree){
		for (int i = 0; i < level; ++i){ cout << " "; }
			cout << p.name << endl;
		show(*p.inner, level+1);
	}
}


int main(int argc, char const *argv[])
{
	int n;
	string temp;
	std::vector<path> * temp_root;
	std::vector<path> root;
	std::vector<path> tree;
	vector<string> splited;
	bool contains;
	size_t pos;

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		pos = temp.find_first_of('\\');
		splited.clear();
		while (pos != string::npos){// парсим строку
			splited.push_back(temp.substr(0, pos));
			temp = temp.substr(pos+1);
			pos = temp.find_first_of('\\');
		}
		if(temp.size() > 0){
			splited.push_back(temp);
		}

		temp_root = & tree;
		for(string str : splited){ 
			contains = false;
			for (path p : (*temp_root)){
				if (p.name ==  str){
					temp_root = p.inner;
					contains = true;
					break;
				}
			}
			if(!contains){
				path dir;
				dir.name = str;
				dir.inner = new vector<path>;
				temp_root -> push_back(dir);
				temp_root = dir.inner;
			}
		}

	}
	show(tree);

	return 0;
}