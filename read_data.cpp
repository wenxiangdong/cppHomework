void write(){
	ofstream out;
	//使用全路径吧
	out.open("C:\\Users\\wenxi\\Documents\\Visual Studio 2013\\Projects\\cppHomework\\Homework2\\Q87\\data.txt", ios::app);
	if (out.is_open()){
		//对应输入逻辑
		out << endl;
		out.close();
	}
}
