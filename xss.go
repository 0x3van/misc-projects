package main

import (
    "bufio"
    "fmt"
    "log"
    "net/http"
    "os"
    "strings"
)

func main() {
    file, err := os.Open("input.txt")
    if err != nil {
        log.Fatal(err)
    }
    defer file.Close()
    scanner := bufio.NewScanner(file)
    for scanner.Scan() {
        url := scanner.Text()
        //fmt.Println(url)
        resp, err := http.Get(url)
        if err != nil {
            log.Fatal(err)
        }
        body := resp.Body
        defer body.Close()
        scanner2 := bufio.NewScanner(body)
        for scanner2.Scan() {
            line := scanner2.Text()
            if strings.Contains(line, "alert('XSS')") {
                fmt.Println("XSS Vulnerability found in: ", url)
            }
        }

    }

    if err := scanner.Err(); err != nil {
        log.Fatal(err)
    }
}
