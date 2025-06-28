/*
🔍 License Plate Prediction and Confidence Evaluation: Reversible Prediction System (C++)
In this project, a reversible prediction mechanism (undo system) has been developed to evaluate and manage the predictions made by an artificial intelligence (AI) model used in license plate recognition systems.
The code simulates the last-in-first-out (LIFO) processing of plate predictions using the stack data structure in the C++ programming language.

🎯 Objective
Predictions made by the AI model may not always have a high confidence rate. This system allows the following:

Each prediction from the AI is added sequentially to a stack.

Predictions with a confidence rate lower than 50% are withdrawn (pop operation).

Predictions with a high confidence rate are accepted and processed.



*/




#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct PlatePrediction {
    string plateText;
    float confidence; // confidence rate

    PlatePrediction(const string& plate, float conf)
        : plateText(plate), confidence(conf) {}
};

void printPrediction(const PlatePrediction& p) {
    cout << "Estimated Plate: " << p.plateText
        << " | Confidence: " << p.confidence * 100 << "%" << endl;
}

int main() {
    stack<PlatePrediction> predictions;

    //  
    predictions.push(PlatePrediction("34ABC123", 0.91));
    predictions.push(PlatePrediction("06XYZ456", 0.87));
    predictions.push(PlatePrediction("35GHJ789", 0.44)); 
    predictions.push(PlatePrediction("01QWE321", 0.96));
    predictions.push(PlatePrediction("16ZZZ999", 0.33));

    cout << "Predicted plates (from last to first):\n";

    // Tahminler geri alınıyor
    while (!predictions.empty()) {
        PlatePrediction p = predictions.top();
        printPrediction(p);

        if (p.confidence < 0.50) {
            cout << "→ LOW CONFIDENCE: Prediction withdrawn (pop).\n";
            predictions.pop(); // incorrect prediction is undone
        }
        else {
            cout << "→ Accepted.\n";
            predictions.pop(); //It is sent to the database and then the extraction process takes place.
        }

        cout << "------------------------\n";
    }

    return 0;
}
