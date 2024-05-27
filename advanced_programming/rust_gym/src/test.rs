use std::collections::HashMap;
use crate::sentence::Sentence;

pub fn magic_sentence(hashmap: &mut HashMap<i32, Sentence>, i: i32, j: i32) -> Result<Sentence, &str> {
    if hashmap.contains_key(&i) && hashmap.contains_key(&j) {
        let first_sentence = match hashmap.get(&i) {
            Some(sentence) => sentence,
            None => return Err("No sentece at first index"),
        };
        let second_sentence = match hashmap.get(&j) {
            Some(sentence) => sentence,
            None => return Err("No sentece at first index"),
        };

        let mut magic_sentence: Vec<String> = Vec::new();

        for ((index1, word1), (index2, word2)) in first_sentence.words.iter().enumerate().zip(second_sentence.words.iter().enumerate()) {
            if word1 == word2 && index1 == index2{
                magic_sentence.push(word1.clone());
            }
        }

        return Ok(Sentence { words: magic_sentence });

    } else {
        return Err("No senteces at this indexes");
    }
}