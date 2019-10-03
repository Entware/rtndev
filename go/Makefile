#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=go
PKG_VERSION:=1.12.10
PKG_RELEASE:=1

PKG_SOURCE:=go$(PKG_VERSION).src.tar.gz
PKG_SOURCE_URL:=https://dl.google.com/go
PKG_HASH:=f56e48fce80646d3c94dcf36d3e3f490f6d541a92070ad409b87b6bbb9da3954

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(BUILD_VARIANT)/$(PKG_NAME)-$(PKG_VERSION)
PKG_UNPACK=$(HOST_TAR) -C $(PKG_BUILD_DIR) --strip-components=1 -xf $(DL_DIR)/$(PKG_SOURCE)

OS=$(shell uname | tr 'A-Z' 'a-z')
bintype:=$(shell uname -m | sed \
	-e 's/i[3-9]86/386/' \
	-e 's/x86_64/amd64/' \
)

# Strip is not recommended for go binaries. It may make binaries unusable
RSTRIP:="/bin/true"

include $(INCLUDE_DIR)/package.mk

ifeq ($(BUILD_VARIANT),nohf)
GOARM=GOARM=5
endif

define Package/go/Default
	SECTION:=lang
	CATEGORY:=Languages
	TITLE:=The Go Programming Language
	URL:=https://golang.org/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/go
	$(call Package/go/Default)
	VARIANT:=hf
endef

define Package/go_nohf
	$(call Package/go/Default)
	VARIANT:=nohf
	DEPENDS:=@(TARGET_armv7_2_6||TARGET_armv7_3_2)
endef

define Package/go/description
 Go is an open source programming language that makes it easy to build simple, reliable, and efficient software.
endef

Package/go_nohf/description=$(Package/go/description)

define Build/Compile
	( \
		cd $(PKG_BUILD_DIR)/src; \
		CGO_ENABLED=0 GOOS=linux GOARCH=$(GOARCH) $(GOARM) $(GOMIPS) GOROOT_BOOTSTRAP=$(STAGING_DIR_HOST)/go ./make.bash --no-clean ; \
	)
	if [ -d $(PKG_BUILD_DIR)/bin/linux_$(GOARCH) ]; then \
		rm $(PKG_BUILD_DIR)/bin/go; \
		rm $(PKG_BUILD_DIR)/bin/gofmt; \
		mv $(PKG_BUILD_DIR)/bin/linux_$(GOARCH)/* $(PKG_BUILD_DIR)/bin/; \
		rm -rf $(PKG_BUILD_DIR)/bin/linux_$(GOARCH); \
	fi
	rm -rf $(PKG_BUILD_DIR)/pkg/bootstrap
	rm -rf $(PKG_BUILD_DIR)/pkg/obj
	[ "$(bintype)" == "$(GOARCH)" ] || rm -rf $(PKG_BUILD_DIR)/pkg/linux_$(bintype)
	[ "$(bintype)" == "$(GOARCH)" ] || rm -rf $(PKG_BUILD_DIR)/pkg/tool/linux_$(bintype)
endef

define Package/go/postinst
#!/bin/sh
echo "Please add /opt/bin/go/bin to your PATH"
echo "Please set GOROOT=/opt/bin/go environment variable to use GO compiler"
endef

Package/go_nohf/postinst=$(Package/go/postinst)

define Package/go/install
	$(INSTALL_DIR) $(1)/opt/bin/go
	$(CP) $(PKG_BUILD_DIR)/{api,bin,lib,misc,pkg,test,doc,src} $(1)/opt/bin/go
endef

Package/go_nohf/install=$(Package/go/install)

$(eval $(call BuildPackage,go))
$(eval $(call BuildPackage,go_nohf))
