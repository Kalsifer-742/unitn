pub struct Sentence {
    pub words: Vec<String>
}

impl Sentence {
    pub fn new_default() -> Self {
        Self {
            words: Vec::new(),
        }
    }
    
    pub fn new(&mut self, string: &str) {
        string.split_whitespace().for_each(|word| self.words.push(word.to_string()));
    }
}