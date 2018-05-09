#
# Copyright (C) 2011-2017 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=asciinema
PKG_VERSION:=2.0.1
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://files.pythonhosted.org/packages/2e/02/cb4aeded6a77e1c23a316a7faeb710b3247dd7294002ccc7123f38f2ade7
PKG_HASH:=8d48baa3a263cfb9536540ee545e5c95e43758520d68c6ebc81a092e20c2a4ea

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
