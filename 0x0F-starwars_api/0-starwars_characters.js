#!/usr/bin/node
// script that prints all characters of a Star Wars movie
const request = require('request');

const endPoint = 'https://swapi-api.hbtn.io/api/films/';
const filmNumber = process.argv[2];

request(`${endPoint + filmNumber}`, (error, response, body) => {
  if (!error && response.statusCode === 200) {
    const data = JSON.parse(body);
    for (const actor of data.characters) {
      request(actor, (error, response, body) => {
        if (!error && response.statusCode === 200) {
          const person = JSON.parse(body);
          console.log(person.name);
        }
      });
    }
  }
});
