
#include "QDebug"

/*bool BankiersAlgorithm::avoidance_algorithm(int stillNeededResources_R[3][4], int assignedResources_C[3][4], int differenceResources_A[4], int availableResources_E[4]){
    int countFinished = 0;
    //qDebug() << "\nR: \n";
        vector<int> markedFinished;
        while(countFinished < 3) {
            bool found = false;
            for(int i = 0; i < 3; i++){
                if(!binary_search(markedFinished.begin(), markedFinished.end(), i)) {
                    int count = 0;
                    for(int j = 0; j < 4; j++) {
                        //qDebug() << stillNeededResources_R[i][j];
                        if(stillNeededResources_R[i][j] <= differenceResources_A[j]) {
                            count++;
                            if(count == 4) {
                                markedFinished.push_back(j);
                                found = true;
                                countFinished++;
                                for(int k = 0; k < 4; k++) {
                                    differenceResources_A[k] += assignedResources_C[i][k];
                                }
                            }
                        } else {
                            break;
                        }
                    }

                }
            }
            if(!found){
                return false; // Deadlock
            }
        }
        return true; // No Deadlock

}
*/


