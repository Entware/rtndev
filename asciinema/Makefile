#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=asciinema
PKG_VERSION:=2.0.2
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://files.pythonhosted.org/packages/a7/71/771c859795e02c71c187546f34f7535487b97425bc1dad1e5f6ad2651357
PKG_HASH:=32f2c1a046564e030708e596f67e0405425d1eca9d5ec83cd917ef8da06bc423

include $(INCLUDE_DIR)/package.mk
include $(TOPDIR)/feeds/packages/lang/python/python3-package.mk

define Package/asciinema
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Terminal
	DEPENDS:=+python3-requests +ncurses-bin +python3-setuptools
	TITLE:=A terminal sessions recorder
	URL:=http://asciinema.org/
	MAINTAINER:=Entware team, https://entware.net
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
