
void removeBad(vector<Movie*>& v)
{
	for (int i = 0; i < v.size(); i++) {
		if (v[i]->rating() < 50) {
			delete v[i];
			v.erase(v.begin() + i);
			i--;
		}
	}
}