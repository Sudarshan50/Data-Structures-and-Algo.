int u = find_set(x,parent);
        int v = find_set(y,parent);
        cout<<u<<" "<<v<<" ";
        if (u == v)
        {   
            cycle = true;
        }
        else
            dsu(x,y,parent,size);