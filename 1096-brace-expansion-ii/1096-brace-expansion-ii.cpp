class Solution {
     using USS = unordered_set<string>;
     int k=0;
    string expr;

    USS add(USS& a,USS& b){
    USS res=a;
    for( auto& s:b){
        if (s.size()) res.insert(s);
    }
    return res;
 }
 USS mul(USS& a,USS& b){
    USS res;
    for(auto& s1:a){
       for(auto& s2:b){
        if((s1+s2).size()>0)
            res.insert(s1+s2);
       }
    }
    return res;
 }

    USS dfs(){
        USS A,B;
        B.insert("");
        while(k<expr.size()&& expr[k]!='}')
        {
            if (expr[k]==','){
                k++;
                A=add(A,B);
                B.clear();
                B.insert("");
            }else if(expr[k]=='{'){
                bool is_add=false;
               // if(k==0||expr[k-1]==',')is_add=true;
                k++;
                USS C=dfs();
                k++;
                if (is_add){
                    A=add(A,B);
                    B=C;
                }else{
                    B=mul(B,C);
                }
            }else{
                 bool is_add=true;
                if(k==0||expr[k-1]==',')is_add=true;
                string s;
                while(k<expr.size() && islower(expr[k]))s+=expr[k++];
                USS C;
                C.insert(s);

                
              //  k++;
               // if (is_add){
                 //   A=add(A,B);
                  //  B=C;
               // }else{
                 B=mul(B,C);
            }
        }
        return add(A,B);
    }
public:
    vector<string> braceExpansionII(string expression) {
       //union :{a,b}={a},{b}
       //multiplication : {a,b}*{c,d}={ac,ad,bc,bd}
       //{{a,b},c}
       //{}
       k=0;
       expr=expression;
       auto uss=dfs();
       auto res=vector<string>(uss.begin(),uss.end());
       sort(res.begin(),res.end());
       return res;
    }
};