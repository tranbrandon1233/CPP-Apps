
void removeOdd(list<int>& li){

	list<int>::iterator it = li.begin();
	while (it != li.end()) 
		//if the value is odd, erase it
		if (*it % 2 != 0) {
			it = li.erase(it);
		}
	//if the value is even, move on to the next value
		else {
			advance(it, 1);
		}
}
