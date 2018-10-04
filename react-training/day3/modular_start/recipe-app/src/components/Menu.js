// import Recipe
import Recipe from './Recipe'
// import '../../stylesheets/Menu.css'
import '../../stylesheets/Menu.css'

// declare the Menu module
const Menu = ({recipes}) =>
    <article>
        <header>
            <h1>Recipes</h1>
        </header>
        <div className="recipes">
            {recipes.map((recipe, i) =>
                <Recipe key={i} {...recipe} />
            )}
            </div>
        </article>
// export default Menu
export default Menu