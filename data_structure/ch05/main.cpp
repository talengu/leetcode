#include<iostream>
#include<string>
#include<vector>
#include"FileOps.h"
#include"SequenceST.h"
#include"BST.h"


int main(int argc, char *argv[])
{
	string filename="bi.txt";
	vector<string> words;
	if(FileOps::readFile(filename,words)){
		cout<<"there are totally "<<words.size() <<" words in " << filename;
		cout<<endl;

		//test BST
		time_t startTime=clock();
		BST<string,int> bst=BST<string,int>();
		for(vector<string>::iterator iter=words.begin();iter!=words.end();iter++){
			int *res=bst.search(*iter);
			if(res==NULL)
				bst.insert(*iter ,1);
			else
				(*res)++;
		}
		cout <<"'god' : " <<*bst.search("god")<<endl;
		time_t endTime=clock();
		cout <<"BST , time: " << double(endTime-startTime)/CLOCKS_PER_SEC << "s."<< endl;
		cout <<endl;
		bst.levelOrder();

		//test SST// 顺序查找法
		startTime=clock();
		SequenceST<string,int>sst=SequenceST<string,int>();
		for(vector<string>::iterator iter=words.begin();iter!=words.end();iter++){
			int *res=sst.search(*iter);
			if(res==NULL)
				sst.insert(*iter ,1);
			else
				(*res)++;
		}
		cout <<"'god' : " <<*bst.search("god")<<endl;
		endTime=clock();
		cout <<"SST , time: " << double(endTime-startTime)/CLOCKS_PER_SEC << "s."<< endl;
		cout <<endl;

	}
	
	return 0;
}

