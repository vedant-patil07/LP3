pragma solidity ^0.8.0;

contract StudentData {
    struct Student {
        uint id;
        string name;
    }

    Student[] public students;

    function addStudent(uint _id, string memory _name) public {
        students.push(Student(_id, _name));
    }

    function showStudents() public view returns (string[] memory, uint[] memory) 
    {
        string[] memory names = new string[](students.length);
        uint[] memory ids = new uint[](students.length);
        for (uint i = 0; i < students.length; i++) 
        {
            names[i] = students[i].name;
            ids[i] = students[i].id;
        }
        return (names,ids);
    }
    function deleteStudent(uint _id) public 
    {
        for (uint i = 0; i < students.length; i++) 
        {
            if (students[i].id == _id) 
            {
                students[i] = students[students.length - 1]; // Move the last student to the position of the student to delete
                students.pop(); // Remove the last student (now duplicated)
                break;
            }
        }
    }

    fallback() external payable {}
    receive() external payable {}
}