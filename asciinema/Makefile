# SPDX-License-Identifier: GPL-3.0-or-later
#
# Copyright (C) 2011-2026 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=asciinema
PKG_VERSION:=3.2.1
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://codeload.github.com/asciinema/asciinema/tar.gz/refs/tags/v$(PKG_VERSION)?
PKG_HASH:=e7e49a09c664a76afc5bc25ca09871eb090bfbe68a2ddbc72750d3cb215d36f1

PKG_LICENSE:=GPL-3.0-or-later
PKG_LICENSE_FILES:=LICENSE

include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/rustlang/rustc-dev/cargo.mk

PKG_BUILD_DEPENDS += getrandom-0216 getrandom-033

define Package/asciinema
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Terminal
	TITLE:=A terminal sessions recorder
	URL:=https://asciinema.org
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/asciinema/description
 asciinema lets you record, stream and replay terminal sessions.
endef

define Package/asciinema/conffiles
/opt/etc/asciinema/config.toml
endef

define Package/asciinema/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/asciinema $(1)/opt/bin
endef

$(eval $(call BuildPackage,asciinema))
