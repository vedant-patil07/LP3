// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract SimpleBank 
{
    uint256 private balance;

    event Deposited(uint256 amount);
    event Withdrawn(uint256 amount);

    function deposit(uint256 amount) public {
        balance += amount;
        emit Deposited(amount);
    }

    function withdraw(uint256 amount) public {
        require(amount <= balance, "Insufficient balance");
        balance -= amount;
        emit Withdrawn(amount);
    }

    function displayBalance() public view returns (uint256) {
        return balance;
    }
}

//emit triggers an event to log data.
//event is a logging mechanism that can be subscribed to by external listeners.
//require checks if a condition is met; if not, it reverts the transaction and prevents further execution.