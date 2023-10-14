#!/usr/bin/node
/*
    Script that prints all characters of a Star Wars movie
*/

const args = process.argv.slice(2);
if (args.length < 1) {
  console.log('Error');
  process.exit(1);
}

const episode = args[0];

const url = `https://swapi-api.hbtn.io/api/films/${episode}`;
const request = require('request');
let characters = [];

request(url, (err, resp, body) => {
  if (err || resp.statusCode !== 200) {
    console.log(err);
    return;
  }

  characters = JSON.parse(body).characters;
  const size = characters.length;
  const array = Array(size).fill(null);
  let data = 0;

  for (let i = 0; i < size; i++) {
    request(characters[i], (erro, respo, bodys) => {
      if (erro || respo.statusCode !== 200) {
        console.log(erro);
      } else {
        array[i] = JSON.parse(bodys).name;
        data++;

        if (data === size) {
          for (let j = 0; j < size; j++) {
            console.log(array[j]);
          }
        }
      }
    });
  }
});
