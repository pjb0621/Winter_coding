use std::io;
fn fibonacci(num: u32) -> u32{
    if num == 0 {
        return 0;
    }
    if num == 1 || num == 2 {
        return 1;
    }
    fibonacci(num-1)+fibonacci(num-2)
}
fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("io error");
    let num:u32 = input.trim().parse().expect("parse error");

    println!("{}", fibonacci(num));
}
