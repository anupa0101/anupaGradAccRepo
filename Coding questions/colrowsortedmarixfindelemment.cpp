#include<iostream>
#include<conio.h>
#include<algorithm>

int main(){
//i binary searched row or cols. whcih every is larger

//BETTER WAY IS <TARGET FO LEFT, R=GREATER THAN TARGET GO DOWN. CTAR FROM  TOP RIGHT. ITS DONE BELLOW
    const int row=4;
    const int col=5;
    int arr[row][col]={{1 , 3, 5, 7, 8},
                       {2 , 6, 9,10,13},
                       {4 ,11,16,18,20},
                       {14,15,17,19,21}};
    int val=7;

    if(row<=col){ //if nummber of rows smaller or eqial to number of cols-to make it o(rowlog(col))
        for(int i=0;i<row;i++){

            if(val>=arr[i][0] && val<=arr[i][col-1]){
                std::cout<<std::binary_search(&arr[i][0],&arr[i][col-1],val);

            }
            
            

        }
    }
     else { //if nummber of cols smaller to number of rows-to make it o(collog(row))
        for(int i=0;i<col;i++){
            if(val>=arr[0][i] && val<=arr[row-1][i]){
                std::cout<<std::binary_search(&arr[0][i],&arr[row-1][i],val);
            }
        }
    }

    //BETTER WAY IS <TARGET FO LEFT, R=GREATER THAN TARGET GO DOWN. CTAR FROM  TOP RIGHT. ITS DONE BELLOW 
    //complexity worst case is m+n
    int r=0,c=col-1;
    
    while(r!=row&& c!=-1){
        int temp=arr[r][c];
        if(temp==val){
            std::cout<<"found";
            break;

        }else if(val<temp){
            c--;//go left
        }
        else{
            r++;
        }
    }

    return 0;
}