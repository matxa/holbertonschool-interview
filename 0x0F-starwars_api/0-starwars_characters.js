#!/usr/bin/node
// script that prints all characters of a Star Wars movie
const request = require('request');
const axios = require('axios');

const endPoint = 'https://swapi-api.hbtn.io/api/films/';
const filmNumber = process.argv[2] ? process.argv[2] : null;
const url = endPoint + filmNumber;

request(url, async function (error, response, body) {
  if (!error && response.statusCode === 200) {
    body = JSON.parse(body);

    for (const character in body.characters) {
      await actor(body.characters[character]);
    }
  }
});

async function actor (url) {
  await axios.get(url)
    .then(function (response) {
      console.log(response.data.name);
    });
}
