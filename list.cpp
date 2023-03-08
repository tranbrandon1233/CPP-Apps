

void listAll(string path, const File* f)  // two-parameter overload
{

    
    if (f != nullptr)
	{
		string additionalSlash = (f->files() == nullptr) ? "" : "/";
		cout << path + additionalSlash << endl;
		if (f->files() != nullptr)
		{
			for (int k = 0; k < f->files()->size(); k++)
			{
                string newPath = path + "/" + f->files()->at(k)->name() ;
				listAll(newPath, f->files()->at(k));
			}
		}
	}
    
}
