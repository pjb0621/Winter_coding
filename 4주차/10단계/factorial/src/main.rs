/*
    팩토리얼
    https://www.acmicpc.net/problem/10872
 */
use std::io;
fn factorial(n: u32) -> u32{
    if n==0 {
        return 1;
    }
    if n==1 {
        return 1;
    }
    factorial(n-1)*n
}
fn main() {
    let mut input = String::new();
    io::stdin()
        .read_line(&mut input)
        .expect("io error");
    let num: u32 = input.trim().parse().expect("parse error");
    println!("{}", factorial(num))
}
