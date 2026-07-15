class Solution {
public:
    int secondsBetweenTimes(string st, string et) {
        int sr=0,ed=0;
        sr=(((st[0]-'0')*10+(st[1]-'0'))*3600)
          +(((st[3]-'0')*10+(st[4]-'0'))*60)
          +(((st[6]-'0')*10+(st[7]-'0')));

        ed=(((et[0]-'0')*10+(et[1]-'0'))*3600)
            +(((et[3]-'0')*10+(et[4]-'0'))*60)
            +(((et[6]-'0')*10+(et[7]-'0')));
        
        return ed-sr;

    }
};