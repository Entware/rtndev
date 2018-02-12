#
# Copyright (C) 2011-2017 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=asciinema
PKG_VERSION:=1.4.0
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://pypi.python.org/packages/21/7a/265e78c86b4b4f8c74c0d8321f6f28faa19f80c5c9d7a834a989ed64154a
PKG_MD5SUM:=507ec769e1e9f8d5146b8c32c5ed54ac

include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/python/python3-package.mk

define Package/asciinema
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Terminal
	DEPENDS:=+python3-requests +ncurses-bin +python3-setuptools
	TITLE:=A terminal sessions recorder
	URL:=http://asciinema.org/
	MAINTAINER:=Entware team, http://entware.net
endef

define Package/asciinema/description
 asciinema lets you record your terminal sessions and share it with other geeks.
endef

define Package/asciinema/conffiles
/opt/etc/asciinema/config
endef

define Build/Compile
	$(call Build/Compile/Py3Mod,,install \
	    --prefix=/opt \
	    --root="$(PKG_INSTALL_DIR)" \
	)
endef

define Package/asciinema/install
	$(INSTALL_DIR) $(1)$(PYTHON3_PKG_DIR)
	$(CP) \
	    $(PKG_INSTALL_DIR)$(PYTHON3_PKG_DIR)/* \
	    $(1)$(PYTHON3_PKG_DIR)
	 $(SED) 's,$(HOST_PYTHON3_BIN),/opt/bin/python3,g' \
	    $(PKG_INSTALL_DIR)/opt/bin/$(PKG_NAME)
	$(INSTALL_DIR) $(1)/opt/bin
	$(CP) $(PKG_INSTALL_DIR)/opt/bin/$(PKG_NAME) $(1)/opt/bin
endef

$(eval $(call BuildPackage,asciinema))
