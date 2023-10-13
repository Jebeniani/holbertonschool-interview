#!/usr/bin/node
// script that prints all characters of a Star Wars movie.

const request = require('request');

const movieId = process.argv[2];
const url = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

request(url, async (error, response, body) => {
  if (error) {
    console.error(error);
  } else {
    const characters = JSON.parse(body).characters;
    for (const characterUrl of characters) {
      await new Promise((resolve, reject) => {
        request(characterUrl, (error, response, body) => {
          if (error) {
            console.error(error);
          } else {
            const character = JSON.parse(body);
            console.log(character.name);
          }
          resolve();
        });
      });
    }
  }
});
