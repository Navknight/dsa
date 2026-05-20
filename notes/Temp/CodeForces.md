<%*
const letter = (await tp.system.prompt("Problem letter (A/B/C...)")).toUpperCase();
const name = await tp.system.prompt("Problem name (e.g. Beautiful Matrix)");
const slug = name.replace(/ /g, "_");
const difficulty = await tp.system.prompt("Difficulty (Easy/Medium/Hard)");
const topics = await tp.system.prompt("Topics (comma-separated, e.g. Arrays, Hash Maps)");
const topicList = topics.split(",").map(t => `"${t.trim()}"`).join(", ");
const topicLinks = topics.split(",").map(t => `[[notes/Topics/${t.trim()}]]`).join(" ");
const url = await tp.system.prompt("CF problem URL");
const codeFile = `CodeForces/${letter}_${slug}.cpp`;
await tp.file.rename(name);
-%>
---
difficulty: <%= difficulty %>
topics: [<%= topicList %>]
source: CodeForces
star: false
link: "<%= url %>"
date: <% tp.date.now("YYYY-MM-DD") %>
code: <%= codeFile %>
---
[[<%= codeFile %>]]
<%= topicLinks %>

[Problem](<%= url %>)

# Approach



# Complexity
- Time:
- Space:
