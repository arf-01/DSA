class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int l=0,h=0,n=s2.length();
        vector<int>mps1(26,0);
        vector<int>mps2(26,0);
        int freq_match=0;
        for(int i=0;i<s1.length();i++)
        {
            mps1[s1[i]-'a']++;
        }

     
        for(int h=0;h<n;h++)
        {     
            
                if(mps1[s2[h]-'a']==0)    
                 {
                   // h++;
                    l=h+1;
                    for(int i=0;i<26;i++)
                    {
                        mps2[i]=0;
                        
                    }

                    continue;
                 }  




              

                 mps2[s2[h]-'a']++;
                

                 while(mps2[s2[h]-'a']>mps1[s2[h]-'a'])
                 {
                     mps2[s2[l]-'a']--;
                    
                     l++;


                 }

                 if(mps2==mps1) return true;




                 
              
            
            

            

            
                
               
        }

        return false;

      
      // return false;
        
    }
};