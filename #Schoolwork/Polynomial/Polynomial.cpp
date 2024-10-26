//
// Created by 王海生 on 2024/4/22.
//

#include "Polynomial.h"

Polynomial::Polynomial()
{
    front = NULL;
    rear = NULL;
}

Polynomial::Polynomial(const Polynomial &original)
{
    Queue_Node * new_front, * new_copy, * original_front = original.front, * new_rear;
    if (original_front == NULL) {
        new_front = NULL;
        new_rear = NULL;
    }
    else { // Duplicate the linked nodes
        new_copy = new_front= new Queue_Node(original_front->entry);
        while (original_front->next != 0) {
            original_front = original_front->next;
            new_copy->next = new Queue_Node(original_front->entry);
            new_copy = new_copy->next;
        }
        new_rear = new_copy;
    }
    front = new_front;
    rear = new_rear;
}

void Polynomial::operator =(const Polynomial &original)
{
    Queue_Node *new_front, *new_copy, *original_front = original.front, *new_rear;
    if (original_front == NULL) {
        new_front=NULL;
        new_rear=NULL;
    }
    else { // Duplicate the linked nodes
        new_copy = new_front= new Queue_Node(original_front->entry);
        while (original_front->next != 0) {
            original_front = original_front->next;
            new_copy->next = new Queue_Node(original_front->entry);
            new_copy = new_copy->next;
        }
        new_rear=new_copy;
    }
    while (!isEmpty()) // Clean out old Queue entries
        serve();
    front= new_front;
    rear=new_rear;
}

void Polynomial::print() const
/*
Post: The Polynomial is printed to cout.
*/
{
    Queue_Node *print_node = front;
    bool first_term = true;
    while (print_node != NULL) {
        Term &print_term =print_node->entry;
        if (first_term) { // In this case, suppress printing an initial '+'.
            first_term = false;
            if (print_term.coefficient < 0)
                cout << "- ";
        }
        else if (print_term.coefficient < 0)
            cout << " - ";
        else
            cout << " + ";
        double r = (print_term.coefficient >= 0)
                   ? print_term.coefficient : -(print_term.coefficient);
        if (r != 1)
            cout << r;
        if (print_term.degree > 1)
            cout << " X^" << print_term.degree;
        if (print_term.degree == 1)
            cout << " X";
        if (r == 1 && print_term.degree == 0)
            cout << " 1";
        print_node = print_node->next;
    }
    if (first_term)
        cout << "0"; // Print 0 for an empty Polynomial.
    cout << endl;
}

void Polynomial::read()
{
    clear();
    double coefficient;
    int last_exponent, exponent;
    bool first_term = true;
    cout << "Enter the coefficients and exponents for the polynomial,one pair per line." << endl
         << "Exponents must be in descending order." << endl
         << "Enter a coefficient of 0 or an exponent of 0 to terminate." << endl;
    do {
        cout << "coefficient? " << flush;
        cin  >> coefficient;
        if (coefficient != 0.0) {
            cout << "exponent? " << flush;
            cin  >> exponent;
            if ((!first_term && exponent >= last_exponent) || exponent < 0) {
                exponent = 0;
                cout << "Bad exponent: Polynomial terminates without its last term."
                     << endl;
            }
            else {
                Term new_term(exponent, coefficient);
                append(new_term);
                first_term = false;
            }
            last_exponent = exponent;
        }
    } while (coefficient != 0.0 && exponent != 0);
    cout << "The following Polynomial has been put into the stack:" << endl;
    print();
}

int Polynomial::degree() const
/*
Post: If the Polynomial is identically 0, a result of -1 is returned.
      Otherwise the degree of the Polynomial is returned.
*/
{
    if (isEmpty())
        return -1;
    Term lead;
    retrieve(lead);
    return lead.degree;
}

void Polynomial::equals_sum(Polynomial p, Polynomial q)
{
    clear();
    while (!p.isEmpty() || !q.isEmpty()) {
        Term p_term, q_term;
        if (p.degree() > q.degree()) {
            p.serve_and_retrieve(p_term);
            append(p_term);
        }
        else if (q.degree() > p.degree()) {
            q.serve_and_retrieve(q_term);
            append(q_term);
        }
        else {
            p.serve_and_retrieve(p_term);
            q.serve_and_retrieve(q_term);
            if (p_term.coefficient + q_term.coefficient != 0) {
                Term answer_term(p_term.degree,
                                 p_term.coefficient + q_term.coefficient);
                append(answer_term);
            }
        }
    }
}

void Polynomial::equals_difference(Polynomial p, Polynomial q)
/*
Post: The Polynomial object is reset as the sum of the two parameters.
*/
{
    clear();
    while (!p.isEmpty() || !q.isEmpty()) {
        Term p_term, q_term;
        if (p.degree() > q.degree()) {
            p.serve_and_retrieve(p_term);
            append(p_term);
        }
        else if (q.degree() > p.degree()) {
            q.serve_and_retrieve(q_term);
            q_term.coefficient = - q_term.coefficient;
            append(q_term);
        }
        else {
            p.serve_and_retrieve(p_term);
            q.serve_and_retrieve(q_term);
            if (p_term.coefficient - q_term.coefficient != 0) {
                Term answer_term(p_term.degree,
                                 p_term.coefficient - q_term.coefficient);
                append(answer_term);
            }
        }
    }
}

void Polynomial::mult_term(Polynomial p, Term t){
    clear();
    while (!p.isEmpty()) {
        Term p_term;
        p.serve_and_retrieve(p_term);
        Term answer_term(p_term.degree+t.degree, p_term.coefficient*t.coefficient);
        if(answer_term.coefficient != 0.0)append(answer_term);
    }
}