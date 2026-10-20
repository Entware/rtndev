# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2024-2026 Entware

include $(TOPDIR)/rules.mk

PKG_NPM_NAME:=pnpm
PKG_NAME:=node-$(PKG_NPM_NAME)
PKG_VERSION:=12.14.0
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NPM_NAME)-$(PKG_VERSION).tgz
PKG_SOURCE_URL:=https://registry.npmjs.org/$(PKG_NPM_NAME)/-/
PKG_HASH:=ea206e35474bf87be9564a85ca70ed1c8ebdc45da55aafb0a3bf09d1ba69b179

PKG_LICENSE:=MIT
PKG_LICENSE_FILES:=LICENSE

HOST_BUILD_DEPENDS:=node/host
HOST_BUILD_PARALLEL:=1

PKG_HOST_ONLY:=1

include $(INCLUDE_DIR)/host-build.mk
include $(INCLUDE_DIR)/package.mk

define Package/node-pnpm
  SUBMENU:=Node.js
  SECTION:=lang
  CATEGORY:=Languages
  TITLE:=Fast, disk space efficient package manager
  URL:=https://pnpm.io/
  DEPENDS:=+node
  BUILDONLY:=1
endef

define Package/node-pnpm/description
  Fast, reliable, and secure dependency management.
endef

TAR_OPTIONS+= --strip-components 1
TAR_CMD=$(HOST_TAR) -C $(1) $(TAR_OPTIONS)

NODEJS_CPU:=$(subst aarch64,arm64,$(subst x86_64,x64,$(subst i386,ia32,$(ARCH))))
HOSTTMPNPM:=$(shell mktemp -u XXXXXXXXXX)

define Host/Compile
	cd $(HOST_BUILD_DIR); \
	$(HOST_MAKE_VARS) \
	npm_config_nodedir=$(STAGING_DIR)/opt/ \
	npm_config_cache=$(TMP_DIR)/npm-cache-$(HOSTTMPNPM) \
	npm install \
		--prefer-offline \
		--no-audit \
		--global-style \
		--install-strategy=shallow \
		--no-save \
		--omit=dev \
		--no-package-lock
	rm -rf $(TMP_DIR)/npm-cache-$(HOSTTMPNPM)
	find $(HOST_BUILD_DIR)/dist -type d -empty -print0 | xargs -0 -r rmdir || true
endef

define Host/Install
	$(INSTALL_DIR) $(1)/lib/node_modules/$(PKG_NPM_NAME)
	$(CP) $(HOST_BUILD_DIR)/{package.json,*.md,native-binary.mjs} \
		$(1)/lib/node_modules/$(PKG_NPM_NAME)/
	$(CP) $(HOST_BUILD_DIR)/{bin,dist,pn,pnpm,pnpx,pnx} \
		$(1)/lib/node_modules/$(PKG_NPM_NAME)/
	$(INSTALL_DIR) $(1)/bin
	$(LN) ../lib/node_modules/$(PKG_NPM_NAME)/pnpm $(1)/bin/pnpm
	$(LN) ../lib/node_modules/$(PKG_NPM_NAME)/pnpx $(1)/bin/pnpx
endef

define Host/Clean
	rm -f $(STAGING_DIR_HOSTPKG)/bin/pnp{m,x}
	rm -rf $(STAGING_DIR_HOSTPKG)/lib/node_modules/pnpm
endef

$(eval $(call HostBuild))
$(eval $(call BuildPackage,node-pnpm))
