# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2025 Entware

# https://github.com/Entware/Entware/issues/1135

include $(TOPDIR)/rules.mk

PKG_NAME:=aide
PKG_VERSION:=0.19.1
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://codeload.github.com/aide/aide/tar.gz/refs/tags/v$(PKG_VERSION)?
PKG_HASH:=d0e8258699ea5d49fd86940995c50d2566390a9447b49052c41c96dbebe41dd7

PKG_MAINTAINER:=Entware team, https://entware.net
PKG_LICENSE:=GPL-2.0-or-later
PKG_LICENSE_FILES:=COPYING

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/aide
  SECTION:=utils
  CATEGORY:=Utilities
  TITLE:=Advanced Intrusion Detection Environment
  URL:=https://aide.github.io
  DEPENDS:=+libnettle +libpcre2 +zlib
endef

define Package/aide/description
  AIDE (Advanced Intrusion Detection Environment, [eyd]) is a file
  and directory integrity checker.
endef

define Build/Prepare
	$(call Build/Prepare/Default)
	echo 'm4_define([AIDE_VERSION], [$(PKG_VERSION)])' > $(PKG_BUILD_DIR)/version.m4
endef

define Package/aide/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/aide $(1)/opt/bin
endef

$(eval $(call BuildPackage,aide))
