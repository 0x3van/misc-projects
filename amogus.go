package main

import (
    "fmt"
    "net/http"
    "net/url"
    "os"
)

func main() {
    if len(os.Args) < 2 {
        fmt.Println("Usage: go run csrf.go <url>")
        os.Exit(1)
    }

    url, err := url.Parse(os.Args[1])
    if err != nil {
        fmt.Println("Error parsing URL:", err)
        os.Exit(1)
    }

    client := &http.Client{}
    req, err := http.NewRequest("GET", url.String(), nil)
    if err != nil {
        fmt.Println("Error creating request:", err)
        os.Exit(1)
    }

    req.Header.Add("Origin", "https://example.com")

    resp, err := client.Do(req)
    if err != nil {
        fmt.Println("Error sending request:", err)
        os.Exit(1)
    }

    fmt.Println("Response:", resp)
}
