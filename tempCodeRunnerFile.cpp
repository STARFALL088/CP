cin >> p[i] >> q[i];

        // srt(p);
        //  srt(q);
        //  lld ans=max({p[n-1]-p[0],q[n-1]-q[0]});
        //  loop(i,n){
        //      ans=fmax(1.00*ans,(lld)sqrtf(p[i]*(p[i])*1.0+q[i]*1.0*(q[i])));
        //      ans=fmax(1.00*ans,(lld)sqrtf(p[i]*(p[i])*1.0+q[n-1-i]*1.0*(q[n-1-i])));

        // }

        if (p[i] == 0)
        {
            y.push_back(q[i]);
        }
        else
            y.push_back(p[i]);
