map<string, int> name_to_id;
    map<int, string> id_to_name;
    int current_id= 1;
    
auto getId = [&](string s) {
        if (name_to_id.find(s) == name_to_id.end()) {
            name_to_id[s] = current_id;
            id_to_name[current_id] = s;
            current_id++;
        }
        return name_to_id[s];
    };