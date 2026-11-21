# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2026 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=bzip3
PKG_VERSION:=1.5.5
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://github.com/iczelia/bzip3/releases/download/$(PKG_VERSION)/
PKG_HASH:=dc3bd8237178e1a2b99d8dcf1f4aeb3593c723788a9863606e121b40784e596d

PKG_LICENSE:=LGPL-3.0-or-later
PKG_LICENSE_FILES:=LICENSE

PKG_INSTALL:=1
PKG_BUILD_PARALLEL:=1

include $(INCLUDE_DIR)/package.mk

define Package/bzip3
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Compression
	TITLE:=BZip3 compression utility
	URL:=https://github.com/iczelia/bzip3
	DEPENDS:=+libpthread
endef

define Package/bzip3/description
 A better, faster and stronger spiritual successor to bzip2.
endef

CONFIGURE_ARGS += --disable-arch-native --enable-static-exe --disable-shared

define Package/bzip3/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/bzip3 $(1)/opt/bin/
	$(LN) bzip3 $(1)/opt/bin/bunzip3
	$(LN) bzip3 $(1)/opt/bin/bz3cat
endef

$(eval $(call BuildPackage,bzip3))
