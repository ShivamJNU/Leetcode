// class Solution {
// public:
    
//     int Glob_count = 0;
    
//     // I have taken the below code of KMP's String matching algorithm from the Geeks for Geeks website (11/02/2024).

// // void computeLPSArray(char* pat, int M, int* lps);

// // Prints occurrences of pat[] in txt[]
// void KMPSearch(char* pat, char* txt)
// {
// 	int M = strlen(pat);
// 	int N = strlen(txt);

// 	// create lps[] that will hold the longest prefix suffix
// 	// values for pattern
// 	int lps[M];

// 	// Preprocess the pattern (calculate lps[] array)
// 	computeLPSArray(pat, M, lps);

// 	int i = 0; // index for txt[]
// 	int j = 0; // index for pat[]
// 	while ((N - i) >= (M - j)) {
// 		if (pat[j] == txt[i]) {
// 			j++;
// 			i++;
// 		}

// 		if (j == M) {
// 			// printf("Found pattern at index %d ", i - j);
//             Glob_count++;
// 			j = lps[j - 1];
// 		}

// 		// mismatch after j matches
// 		else if (i < N && pat[j] != txt[i]) {
// 			// Do not match lps[0..lps[j-1]] characters,
// 			// they will match anyway
// 			if (j != 0)
// 				j = lps[j - 1];
// 			else
// 				i = i + 1;
// 		}
// 	}
// }

// // Fills lps[] for given pattern pat[0..M-1]
// void computeLPSArray(char* pat, int M, int* lps)
// {
// 	// length of the previous longest prefix suffix
// 	int len = 0;

// 	lps[0] = 0; // lps[0] is always 0

// 	// the loop calculates lps[i] for i = 1 to M-1
// 	int i = 1;
// 	while (i < M) {
// 		if (pat[i] == pat[len]) {
// 			len++;
// 			lps[i] = len;
// 			i++;
// 		}
// 		else // (pat[i] != pat[len])
// 		{
// 			// This is tricky. Consider the example.
// 			// AAACAAAA and i = 7. The idea is similar
// 			// to search step.
// 			if (len != 0) {
// 				len = lps[len - 1];

// 				// Also, note that we do not increment
// 				// i here
// 			}
// 			else // if (len == 0)
// 			{
// 				lps[i] = 0;
// 				i++;
// 			}
// 		}
// 	}
// }
    
//     int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
//         vector<int> vec1;
        
//         for(int i=1; i<nums.size(); i++){
//             if(nums[i] > nums[i-1]){
//                 vec1.push_back(1);
//             }else if(nums[i] < nums[i-1]){
//                 vec1.push_back(-1);
//             }else if(nums[i] == nums[i-1]){
//                 vec1.push_back(0);
//             }
//         }
        
//         string pat = "";
//         string txt = "";
        
//         for(auto &e: pattern){
//             if(e==-1){
//                 pat.push_back('2');
//             }else if (e==1){
//                 pat.push_back('1');
//             }else if(e==0){
//                 pat.push_back('0');
//             }
//         }
        
//         for(auto &e: vec1){
//             if(e==-1){
//                 txt.push_back('2');
//             }else if (e==1){
//                 txt.push_back('1');
//             }else if(e==0){
//                 txt.push_back('0');
//             }
//         }
        
// //         char* pat1 = new char[pat.length() + 1]; 
    
    
// //         pat1[pat.length()] = '\0'; 
      
// //     for (int i = 0; i < pat.length(); i++) { 
// //         pat1[i] = pat[i]; 
// //     } 
        
// //         char* txt1 = new char[txt.length() + 1]; 
    
    
// //         txt1[txt.length()] = '\0'; 
      
// //     for (int i = 0; i < txt.length(); i++) { 
// //         txt1[i] = txt[i]; 
// //     } 
        
//         char* pat1 = &pat[0]; 
//         char* txt1 = &txt[0];
        
         
        
//         KMPSearch(pat1, txt1);
        
//         return Glob_count;
//     }
// };

class Solution {
public:
// The below code is the edited version of the KMP Algorithm's code available on the GeeksForGeeks Website.

vector<int> Glob;

void computeLPSArray(vector<int> &pat, int M, vector<int> &lps)
{
    int len = 0;

    lps[0] = 0;

    int i = 1;

    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(vector<int> &pat, vector<int> &txt)
{

    int M = pat.size();
    int N = txt.size();

    vector<int> lps(M);

    computeLPSArray(pat, M, lps);

    int i = 0;
    int j = 0;
    while ((N - i) >= (M - j))
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }

        if (j == M)
        {
            // cout << "Found pattern at index " << i - j << endl;

            Glob.push_back((i - j));

            j = lps[j - 1];
        }

        else if (i < N && pat[j] != txt[i])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i = i + 1;
            }
        }
    }
}
    
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        vector<int> vec1;
        
        for(int i=1; i<nums.size(); i++){
            if(nums[i] > nums[i-1]){
                vec1.push_back(1);
            }else if(nums[i] < nums[i-1]){
                vec1.push_back(-1);
            }else if(nums[i] == nums[i-1]){
                vec1.push_back(0);
            }
        }
        
        KMPSearch(pattern, vec1);
        
        return Glob.size();
    }
};


