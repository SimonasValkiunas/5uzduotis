# 5uzduotis

# Šalti dalykai:
  
Idėja paprasta - he's = he is, he'd = he had, haven't = have not ir t.t.

                int found = zodis.find('');
                if( found != std::string::npos){
                    std::string::iterator itx = zodis.begin()+found;
                    std::string::iterator it = zodis.end();
                    if(zodis[found+1]=='t') {
                                    zodis.erase(itx-2,it);
                                    Mmap.insert(std::pair <std::string, int> ("not",eilute));}
                    if(zodis[found+1]=='s') {
                        Mmap.insert(std::pair <std::string, int> ("is",eilute));
                        zodis.erase(itx,it);
                        Mmap.insert(std::pair <std::string, int> (zodis,eilute));
                    }
                    if(zodis[found+1]=='v') {
                        zodis.erase(itx,it);
                        Mmap.insert(std::pair <std::string, int> (zodis,eilute));
                        Mmap.insert(std::pair <std::string, int> ("have",eilute));
                    }
                    if(zodis[found+1]=='d')
                    {Mmap.insert(std::pair <std::string, int> ("had",eilute));
                    zodis.erase(itx,it);
                    Mmap.insert(std::pair <std::string, int> (zodis,eilute));}
                    } else Mmap.insert(std::pair <std::string, int> (zodis,eilute));
                   
