#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;
vector<int> pq;


bool isPrime(int n) {

    bool is_prime = true; 
    int i = 2; 

    if (n == 0 || n == 1) {
        is_prime = false;
        return is_prime;
  }

  // loop to check if n is prime
  for (i = 2; i <= n/2; ++i) {
    if (n % i == 0) {
      is_prime = false;
      return is_prime;
      //break;
    }
  }
  return is_prime;
  
};

void findFactors (int num) {

   int product;
  // cout << "goes in function" << endl;

   for (unsigned i = 2; i < num; ++i){
    //cout << "in loop";
      if (isPrime(i)){
         for(unsigned j = 2; j < num; ++j){
            if(isPrime(j)){
               //cout << "loop"; 
                product = i*j;
               
               if (product == num){
                 // cout << "loop inside";
                  pq.push_back(i);
                  pq.push_back(j);
                  break;
               }

            }
         }
      }
   }
   
//    for loop (int i - 900)
//         check if i prime  -> isPrime
//         if isPrime: 
//             for loop (j - 900)
//                 check if is Prime -> isPrime
//                 if isPrime: multiply it with i 
//                     check if equal to num; 

// check all prime numbers from 1 = square root(n)
};



int findPhi()
{
   int p = pq.at(0);
   int q = pq.at(1);
    int phiN;
    phiN = (p-1)*(q-1);
    return phiN;

};
int findD(int e, int phi){
    int d; 
    int tempD1;
    int tempD2; 
    
    vector<int> multiplesofe;
    for (int i = 1; i < phi; ++i) {
        //cout << "in the multiples loop" << endl;
        int num = i * e;
        //cout << num << " ";
        multiplesofe.push_back(num);
    }
    cout << endl;

    // for (int i = 0; i < multiplesofe.size(); ++i)
    // {
    //   cout << "multiples of e: " << multiplesofe.at(i) << " " << endl;
    // }
    //cout << "out of loop" << endl;

   //  for (int i = 0; i < pq.size(); ++i)
   //  {
   //    if (pq.at(i) < phi)
   //    {
   //       pq.pop_front();
   //    }
   //  }

    for (int i = 2; i < phi; ++i){
       // cout << "in the phi loop" << endl;
        for (int j = 1; j < multiplesofe.size(); ++j) {
            //cout << "in the check phi and multofe loop " << j << endl;
            if ((phi * i) == (multiplesofe.at(j)+1) || (phi * i) == (multiplesofe.at(j)-1)){
                tempD1 = i;
                //cout << tempD1 << endl;
                tempD2 = j+1;
                //cout << tempD2 << endl;
                i = phi;
                break;
                
            }
        }
    
    }
    if((tempD2*e - tempD1*phi) == 1) {
        
        d = tempD2;

    }else {
        d = tempD1; 
    }

    return d;
}

//C^d(mod n) = 1
int modBySquares (int C, int d, int n){
    int constant = 1;
    int end;
    while (d > 1){
        if (d % 2 != 0){
            constant = constant * C; 
            constant = constant % n;
            --d;
        }
        C = C * C; 
        C = C % n;
        d = d / 2;
    }

    end = (C * constant) % n;
    return end;
}

int main()
{ 
    //130
    
    //30  
    std::vector <char> message(35);
    message = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',  ' ', '\"', '.', ',', '\''};

    int phi;
    int d;
    int n;
    int messageInput;
    int e;
    int messageLength;
    int decrypt;

    cout << "Enter an e value" << endl;
    cin >> e;
    cout << "Enter a n value" << endl; 
    cin >> n;
    cout << "Enter the length of message" << endl; 
    cin >> messageLength;

    std::vector <int> encryptedMsg;
    cout << "Enter the message(encrypted)" << endl;
    for (int i = 0; i < messageLength; ++i) {
        cin >> messageInput;
        //cout << messageInput << " ";
        encryptedMsg.push_back(messageInput);
        //cout << encryptedMsg.at(i) << " "; 
    }
   
    
//    if(isPrime(367)) {
//      cout << "yes its prime" << endl;
//    }else{
//     cout << "no" << endl;
//    }


   
   
    findFactors(n);
    phi = findPhi(); 
    d = findD(e,phi);

    cout << pq.at(0) << " " << pq.at(1) << " " << phi << " " << d << endl; 
    
//     for (int i = 0; i < messageLength - 1; ++i){
//         cout << encryptedMsg.at(i) << " " << endl; 
//    }

    for (int i = 0; i < messageLength; ++i){
        //cout << encryptedMsg.at(i) << " " << endl; 
        decrypt = modBySquares(encryptedMsg.at(i),d,n);
        //cout << decrypt << endl;
        cout << message.at(decrypt - 3) << " "; 
   }
   cout << endl;


     
    // cout << d << endl;
    

//GET PUBLIC KEY P(e,n)
//FIND p,q,phi(n),d

//1.Find the factors of n

//2.used the totiet rule to find phi(n)
//3.find d: for loop 
//4.get letter 

   return 0;
};