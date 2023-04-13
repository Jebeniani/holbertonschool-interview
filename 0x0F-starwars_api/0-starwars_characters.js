#!/usr/bin/node

/* eslint-disable consistent-return */

/* eslint-disable no-unused-vars */

/* eslint-disable no-await-in-loop */

const request = require('request');

const filmId = process.argv[2];
const url = `https://swapi-api.hbtn.io/api/films/${filmId}`;

request(url, async (err, response, body) => {
  if (err) {
    console.log(err);
  }
  const charURLList = JSON.parse(body).characters;

  for (const charURL of charURLList) {
    await new Promise((resolve, reject) => {
      request(charURL, (err, res, body) => {
        if (err) {
          return console.error(err);
        }

        console.log(JSON.parse(body).name);
        resolve();
      });
    });
  }
});
