/*
// Definition for Employee.
class Employee {
    public int id;
    public int importance;
    public List<Integer> subordinates;
};
*/

class Solution {
    int recuu(int id,HashMap<Integer,Employee>mp){
        int res=(mp.get(id)).importance;
        for(int subId:(mp.get(id)).subordinates)res+=recuu(subId,mp);
        return res;    
    }
    public int getImportance(List<Employee> employees, int id) {
        HashMap<Integer,Employee>mp=new HashMap<>();
        for(Employee obj: employees)mp.put(obj.id,obj);
        return recuu(id,mp);
    }
}