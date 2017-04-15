//
// Created by Prince Chawla on 4/5/17.
//

#ifndef ADVDBTEST_TESTBULKLOAD_H
#define ADVDBTEST_TESTBULKLOAD_H

#include "../QuadTreeLib.h"
#include "../QPoint.h"
#include "../prQuadTree.h"
#include "../prQuadNode.h"

using namespace std;

//change the func to return prQuadtree and return * pointing to heap prQuadTree

prQuadTree* bulkLoadPrQuadTree(std::string inputFilePath ){
    prQuadTree *prQt = new prQuadTree(0,0,200,200);

    ifstream fileToLoad (inputFilePath);
    string line;

    float val = 0.0;
    int i = 0;
    cout<< fileToLoad.is_open()<<endl;

    if ( fileToLoad.is_open() ) {
        while (getline(fileToLoad, line)) {
            stringstream ss(line);
            QPoint* temp = new QPoint();
            vector<float> vect;
            while (ss >> val) {
                vect.push_back(val);
                if (ss.peek() == ',')
                    ss.ignore();
            }
            temp->set(vect.at(0),vect.at(1),i);
            prQt->insert(temp);

        }

        i++;
    }
    fileToLoad.close();

    return prQt;
}


void testBulkLoadPrQuadTree() {

    cout << "\n\n\n Bulkloading Of Points - Started" << endl;
    std:: string fileToLoadPath;
    fileToLoadPath = "/Users/ravichandran/Documents/Misc/Docs/ASU_Subjects/Spring_17/ADVDB/Project/Code/advances-quadtree/new/advdbSpatialTest/Test/point.csv";
//    fileToLoadPath = "/Users/princechawla/advances-quadtree/new/advdbSpatialTest/Test/point.csv";

    prQuadTree* temp = bulkLoadPrQuadTree(fileToLoadPath);
    cout << "\n\n\n Bulkloading Of Points - Ended" << endl;
}


#endif //ADVDBTEST_TESTBULKLOAD_H
