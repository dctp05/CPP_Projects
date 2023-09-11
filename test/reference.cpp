#include <iostream>
#include <string>

using namespace std;

struct book {
    int pages;
    double price;
    string author;
};

void print_shit(struct book[], int);

int main () {
    int pages[217] = {113, 244, 118, 38, 224, 130, 55, 310, 392, 160, 246, 172, 86, 327, 95, 289, 326, 347, 237, 275, 282, 57, 364, 306, 154, 342, 229, 126, 122, 67, 378, 246, 271, 81, 373, 140, 369, 283, 183, 281, 367, 36, 327, 110, 183, 229, 273, 142, 102, 197, 300, 131, 220, 178, 37, 221, 49, 343, 351, 361, 250, 259, 287, 64, 176, 253, 344, 260, 96, 196, 367, 111, 321, 284, 284, 79, 119, 178, 322, 254, 248, 247, 257, 26, 48, 363, 232, 173, 68, 15, 55, 230, 210, 320, 12, 397, 307, 252, 362, 292, 392, 108, 324, 48, 128, 287, 81, 85, 316, 350, 95, 42, 322, 1, 308, 115, 319, 129, 341, 221, 39, 212, 260, 384, 45, 391, 101, 135, 102, 42, 325, 70, 49, 356, 317, 128, 85, 93, 208, 329, 82, 374, 38, 95, 101, 265, 30, 196, 21, 171, 344, 299, 8, 362, 122, 58, 52, 386, 59, 288, 324, 171, 329, 212, 328, 299, 326, 96, 22, 364, 128, 367, 155, 118, 372, 69, 372, 272, 212, 149, 362, 246, 386, 125, 273, 102, 104, 298, 382, 347, 70, 394, 321, 120, 60, 102, 202, 55, 260, 234, 288, 372, 143, 184, 345, 24, 239, 66, 98, 356, 1, 314, 319, 47, 387, 328, 191};
    double prices[217] = {26.68, 51.97, 29.12, 10.73, 32.02, 81.61, 87.03, 33.07, 62.41, 83.28, 58.66, 95.70, 26.05, 12.45, 30.39, 29.33, 17.62, 30.52, 11.01, 91.44, 54.65, 85.06, 84.54, 65.70, 71.98, 78.09, 13.95, 40.09, 47.00, 41.96, 75.77, 57.49, 50.63, 26.92, 33.15, 34.81, 82.46, 80.29, 52.91, 98.41, 9.69, 94.14, 10.80, 21.05, 35.51, 89.88, 30.31, 82.30, 88.98, 91.46, 2.99, 42.90, 24.06, 43.99, 9.96, 82.19, 82.07, 39.81, 42.08, 76.60, 60.39, 16.03, 35.14, 6.50, 37.93, 33.90, 80.36, 89.28, 46.08, 89.20, 88.39, 14.51, 30.93, 79.66, 50.59, 33.12, 10.70, 74.05, 20.89, 99.29, 26.82, 54.31, 66.64, 69.10, 42.07, 17.23, 10.85, 58.19, 20.35, 70.19, 63.03, 17.13, 17.71, 13.89, 80.26, 79.60, 28.82, 24.79, 76.72, 15.87, 31.77, 58.68, 21.45, 42.40, 56.53, 65.39, 72.73, 92.24, 55.90, 77.68, 41.00, 76.50, 39.13, 79.81, 71.46, 67.00, 65.90, 14.21, 87.56, 17.10, 41.13, 92.35, 86.18, 51.01, 99.78, 95.10, 5.69, 1.16, 55.43, 73.35, 58.08, 97.49, 58.99, 27.70, 99.30, 33.82, 6.26, 87.84, 3.11, 43.50, 90.26, 41.44, 67.84, 34.65, 96.20, 48.09, 12.81, 86.26, 50.77, 91.99, 86.32, 44.11, 53.96, 84.74, 6.24, 13.44, 6.03, 8.71, 17.72, 61.05, 91.30, 12.39, 33.20, 78.69, 73.72, 76.19, 19.17, 64.23, 33.57, 77.89, 39.43, 19.47, 74.95, 13.71, 86.71, 42.26, 85.75, 50.41, 49.22, 42.76, 86.54, 80.61, 81.95, 47.39, 68.10, 5.98, 8.32, 30.32, 67.81, 22.23, 68.48, 19.94, 74.12, 29.14, 28.51, 70.34, 61.31, 77.02, 83.27, 15.22, 38.39, 93.69, 62.28, 64.20, 8.12, 60.94, 95.12, 7.65, 26.99, 36.17, 28.64, 70.82, 71.34, 79.07, 86.74, 52.53, 24.53};
    string authors[217] = {"Abbott, Eleanor Hallowell", "Abdullah, Achmed", "Adams, Andy", "Ade, George", "Aesop,", "Akhmatova, Anna", "Alcott, Louisa May", "Aldrich, Thomas Bailey", "Alger, Horatio", "Alighieri, Dante", "Altsheler, Joseph A.", "Andersen, Hans Christian", "Anderson, Sherwood", "Andreyev, Leonid", "Angelou, Maya", "Anonymous,", "Appleton, Victor", "Aristotle,", "Arthur, T.S.", "Asbjornsen, Peter", "Asimov, Isaac", "Assis, Joaquim Maria Machado de", "Atherton, Gertrude", "Atwood, Margaret", "Auden, W.H.", "Aumonier, Stacy", "Austen, Jane", "Bai, Li", "Baldwin, James", "Ballou, Sullivan", "Balzac, Honore de", "Barbour, Ralph Henry", "Barr, Robert", "Barrie, James M.", "Barton, Clara", "Basho, Matsuo", "Bastiat, Frédéric", "Bates, Katharine", "Baum, L. Frank", "Beach, Rex Ellingwood", "Bell, Nancy", "Bellamy, Francis", "Bellamy, Edward", "Bennett, Arnold", "Benson, Edward", "Benson, Robert Hugh", "beresford, John", "Berlin, Irving", "Bierce, Ambrose", "Bjørnson, Bjørnstjerne", "Blackmore, R. D.", "Blackwood, Algernon", "Blaisdell, Albert", "Blake, William", "Boccaccio, Givoanni", "Boswell, James", "Bradbury, Ray", "Brady, Loretta", "Brittain, Vera", "Bronte, Charlotte", "Bronte, Emily", "Brown, Fredric", "Browning, Elizabeth", "Browning, Robert", "Bryant, William", "Buck, Pearl", "Bunin, Ivan", "Bunner, Henry", "Bunyan, John", "Burnett, Frances Hodgson", "Burns, Robert", "Burr, Amelia", "Burroughs, Edgar Rice", "Butler, Ellis", "Byron, Lord", "Capote, Truman", "Carroll, Lewis", "Carryl, Guy", "Cather, Willa", "Cavendish, Margaret", "Cervantes, Miguel de", "Chambers, George F.", "Chambers, Robert", "Chaucer, Geoffrey", "Chekhov, Anton", "Chesnutt, Charles W.", "Chesterton, G.K.", "Chittenden, Gerald", "Chopin, Kate", "Christie, Agatha", "Clarke, Marcus", "Cohan, George", "Coleridge, Sara", "Coleridge, Samuel", "Collins, William Wilkie", "Collodi, Carlo", "Comer, Cornelia", "Confucius,", "Connell, Richard", "Conrad, Joseph", "Cooke, Grace MacGowan", "Cooper, James Fenimore", "Cope, Wendy", "Crane, Stephen", "Crevecoeur, J. Hector St. John de", "Crompton, Richmal", "Dahl, Roald", "Davis, Richard Harding", "Defoe, Daniel", "Dell, Ethel M.", "De Quincey, Thomas", "De Vere, Aubrey", "Dick, Philip", "Dickens, Charles", "Dickinson, Emily", "Donahey, William", "Donne, John", "Dos Passos, John", "Dostoevsky, Fyodor", "Douglass, Frederick", "Dowson, Ernest", "Doyle, Sir Arthur Conan", "Dreiser, Theodore", "Du Bois, W.E.B.", "Dumas, Alexandre", "Dumas fils, Alexandre", "Dunbar, Paul Laurence", "Dunbar-Nelson, Alice", "Dyer, Walter", "Eaton, Edit Maude", "Edwards, Amelia Ann Blanford", "Edwards, Jonathan", "Eliot, T. S.", "Eliot, George", "Emerson, Ralph Waldo", "Emmett, Daniel", "Equiano, Olaudah", "Everett-Green, Evelyn", "Faulkner, William", "Ferber, Edna", "Fillmore, Parker", "Fisher, Dorothy", "Fitzgerald, F. Scott", "FitzGerald, Edward", "Flaubert, Gustave", "Foote, Mary Hallock", "Ford, Ford", "Forster, Edward", "Fox, George", "Franklin, Miles", "Franklin, Benjamin", "Freeman, Richard", "Freeman, Mary E. Wilkins", "Frost, Robert", "Fuller, Margaret", "Gale, Zona", "Galsworthy, John", "Gannett, Ruth", "Garshin, Vsevolod", "Gaskell, Elizabeth", "Ghosal, Swarnakumari", "Gibran, Kahlil", "Gilman, Charlotte Perkins", "Gilmore, Patrick", "Gissing, George", "Glaspell, Susan", "Gogol, Nikolai Vasilievich", "Goose, Mother", "Gordon, Elizabeth", "Gorky, Maxim", "Goudiss, C. Houston", "Grahame, Kenneth", "Grant, Ulysses", "Graves, Robert", "Grey, Zane", "Grimm, Jacob and Wilhelm", "Guthrie, Woody", "Hale, Edward Everett", "Haley, William", "Hamilton, Alexander", "Hardy, Thomas", "Harper, Francis", "Harte, Bret", "Harvey, William Fryer", "Hawthorne, Nathaniel", "Hearn, Lafcadio", "Hemingway, Ernest", "Henry, O.", "Herford, Oliver", "Herrick, Robert", "Herrick, Robert Welch", "Hesse, Hermann", "Higgins, Violet Moore", "Hoffmann, Ernst Theodor Wilhelm Amadeus", "Holmes, Oliver", "Holmes, Mary Jane", "Homer,", "Hopkins, Livingston", "Housman, A. E.", "Howe, Julia", "Howells, William Dean", "Hughes, Langston", "Hughes, Louis", "Hugo, Victor", "Hunter, Evan", "Hurston, Zora", "Huxley, Aldous"};
    book books[217];
    for (int j=0; j<217; j++) {
        books[j].pages = pages[j];
        books[j].price = prices[j];
        books[j].author = authors[j];
    }
    print_shit(books, 217);
}

void print_shit(book book_list[], int num_pg) {
    int k=1;
    for(int i=0; i<num_pg; i++) {
        if(book_list[i].pages > 200) {
            cout << k++ << ". " << book_list[i].pages << " pages | $" << book_list[i].price << " | " << book_list[i].author << endl;
        }
    }
}
