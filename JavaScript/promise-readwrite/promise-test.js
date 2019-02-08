const fs = require('fs');

const loadFile = (filePath) => {
    return new Promise((resolve, reject) => {
        fs.readFile(filePath, 'utf8', (err, data) => {
            if (err) {
                reject(err);
            }
            else {
                resolve(data);
            }
        });
    });
}

const writeFile = (filePath, data) => {
    return new Promise((resolve, reject) => {
        fs.writeFile(filePath, data, err => {
            if (err) {
                reject(err);
            }
            else {                
                resolve('Wrote file ' + filePath);
            }
        });
    })
}

let infile = loadFile('big.txt');

infile.then(dat => {
    let outfile = writeFile('big2.txt', dat).catch(e => {
        console.log(e);
    })
}).catch(e => {
    console.log(e)
});