#include <code_practise/utils/table.hpp>
#include <code_practise/macro/file.hpp>
#include <code_practise/utils/defer.hpp>
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdint>
//求最长子串
int main(){
	F_IO;
	std::vector<char>X,Y;
	auto * target = &X;
	while(true){
		char buf='E';
		in.get(buf);
		if(in.eof())
			break;
		else if(buf=='\n'){
			target = &Y;
			continue;
		}
		(*target).push_back(buf);
	}
	table<int> len(X.size()+1,Y.size()+1);
	table<std::string> hint(X.size()+1,Y.size()+1);
	len.setValueAll(0);
	hint.setValueAll(" ");
	for(uint64_t i = 1;i<X.size()+1;i++){
		for(uint64_t j = 1;j<Y.size()+1;j++){
			if(X[i-1]==Y[j-1]){
				len[i][j] = len[i-1][j-1]+1;
				hint[i][j]="↖"; 
			}else if(len[i-1][j]>=len[i][j-1]){
				len[i][j] = len[i-1][j];
				hint[i][j]="↑";
			}else{
				len[i][j] = len[i][j-1];
				hint[i][j]="←";
			}
		}
	}
	for(uint64_t i=0;i<X.size()+1;i++){
		for(uint64_t j=0;j<Y.size()+1;j++){
			out<<std::setw(3)<<len[i][j]
			<<hint[i][j];
		}
		out<<std::endl<<std::endl;
	}

}
