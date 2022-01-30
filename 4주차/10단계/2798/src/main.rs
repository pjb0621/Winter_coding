use std::io;
fn backtrack(nums: &Vec<i32>, selected: &mut Vec<i32>, index: usize, result: &mut i32, max: i32) {
    if selected.len() == 3 {
        let temp = selected.iter().sum();
        if temp <= max && temp > *result{
            *result = temp;
        }
        return;
    }
    
    for i in index..nums.len() {
        selected.push(nums[i]);
        backtrack(&nums, selected, i+1, result, max);
        selected.pop();
    }
}
fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("io error");
    let nums: Result<Vec<i32>, _> = input.trim().split(' ').map(str::parse).collect();
    let nums = nums.expect("parse error");
    let n = nums[0];
    let m = nums[1];
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("io error");
    let nums: Result<Vec<i32>, _> = input.trim().split(' ').map(str::parse).collect();
    let nums = nums.expect("parse error");
    let mut result: i32 = 0;
    let mut selected: Vec<i32> = Vec::new();
    backtrack(&nums, &mut selected, 0, &mut result, m);
    println!("{}", result);

}
