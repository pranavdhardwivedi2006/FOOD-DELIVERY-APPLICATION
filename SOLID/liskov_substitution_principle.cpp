#include<iostream>
#include<vector>
using namespace std;

class NonWithdrawableAccount {
public:
    virtual void deposit(double) = 0;
};

class WithdrawableAccount : public NonWithdrawableAccount {
public:
    virtual void withdraw(double) = 0;
};

class SavingsAccount : public WithdrawableAccount {
double balance;
public :
    SavingsAccount() {
        balance = 0;
    }

    void deposit(double amount) override {
        balance += amount;
        cout << "Successfully deposited\n";
    }

    void withdraw(double amount) override {
        if(amount > balance) cout << "Insufficient Balance\n";
        else {
            balance -= amount;
            cout << "Successfully withdrawed.\n";
        }
    }
};

class CurrentAccount : public WithdrawableAccount {
double balance;
public :
    CurrentAccount() {
        balance = 0;
    }

    void deposit(double amount) override {
        balance += amount;
        cout << "Successfully deposited\n";
    }

    void withdraw(double amount) override {
        if(amount > balance) cout << "Insufficient Balance\n";
        else {
            balance -= amount;
            cout << "Successfully withdrawed.\n";
        }
    }
};

class FixedDepositAccount : NonWithdrawableAccount {
double balance = 0;
public :
    FixedDepositAccount() {
        balance = 0;
    }

    void deposit(double amount) override {
        balance += amount;
        cout << "Successfully deposited\n";
    }

    void withdraw(double amount) {
        throw logic_error("Withdraw not allowed in Fixed Deposit Account.");
    }
};

class BankClient {
private:
vector<NonWithdrawableAccount*> depositOnlyAccounts;
vector<WithdrawableAccount*> withdrawableAccounts;

public:
    BankClient(vector<WithdrawableAccount*> withdrawableAccounts, vector<NonWithdrawableAccount*> depositOnlyAccounts) {
        this->withdrawableAccounts = withdrawableAccounts;
        this->depositOnlyAccounts = depositOnlyAccounts;
    }

    void processTransactions() {
        for(WithdrawableAccount* acc : withdrawableAccounts) {
            acc->deposit(1000);
            acc->withdraw(500);
        }

        for(NonWithdrawableAccount* acc : depositOnlyAccounts) {
            acc->deposit(5000);
        }

    }
};