set -e
 
GITHUB_USER="hi0ki"
 
REPOS=(
  "42-CPP_00 cpp-module-00"
  "42-CPP_01 cpp-module-01"
  "42-CPP_02 cpp-module-02"
  "42-CPP_03 cpp-module-03"
  "42-CPP_04 cpp-module-04"
  "42-CPP_05 cpp-module-05"
  "42-CPP_06 cpp-module-06"
  "42-CPP_07 cpp-module-07"
  "42-CPP_08 cpp-module-08"
  "42-CPP_09 cpp-module-09"
)
 
# Auto-commit any uncommitted changes before starting
if ! git diff --quiet || ! git diff --cached --quiet; then
  echo "-> Uncommitted changes detected, committing them first..."
  git add .
  git commit -m "chore: save existing files before merging repos"
fi
 
for ENTRY in "${REPOS[@]}"; do
  REPO_NAME=$(echo $ENTRY | cut -d' ' -f1)   # e.g. 42-CPP_00
  FOLDER=$(echo $ENTRY | cut -d' ' -f2)       # e.g. cpp-module-00
  REPO_URL="https://github.com/$GITHUB_USER/$REPO_NAME.git"
 
  echo ""
  echo "========================================="
  echo "  Processing: $REPO_NAME -> $FOLDER/"
  echo "========================================="
 
  # 1. Add remote
  echo "-> Adding remote..."
  git remote add "$FOLDER" "$REPO_URL"
 
  # 2. Fetch
  echo "-> Fetching..."
  git fetch "$FOLDER"
 
  # 3. Detect branch
  if git ls-remote --heads "$FOLDER" main | grep -q main; then
    BRANCH="main"
  else
    BRANCH="master"
  fi
  echo "-> Detected branch: $BRANCH"
 
  # 4. Merge history only (keeps your files untouched)
  echo "-> Merging history..."
  git merge "$FOLDER/$BRANCH" --allow-unrelated-histories --strategy=ours -m "Merge history of $REPO_NAME"
 
  # 5. Read tree directly into subfolder
  echo "-> Reading tree into $FOLDER/..."
  git read-tree --prefix="$FOLDER/" -u "$FOLDER/$BRANCH"
 
  # 6. Commit
  echo "-> Committing..."
  git commit -m "Add $REPO_NAME into $FOLDER/"
 
  # 7. Remove remote
  echo "-> Removing remote..."
  git remote remove "$FOLDER"
 
  echo "✅ Done: $REPO_NAME -> $FOLDER/"
done
 
echo ""
echo "========================================="
echo "  Pushing to origin..."
echo "========================================="
git push origin HEAD
 
echo ""
echo "🎉 Done! All modules are in the monorepo with full commit history."